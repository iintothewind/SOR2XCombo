# SOR2XCombo → Godot 迁移:架构映射方案

> 本文档定义核心战斗系统在 Godot 4.x 中的映射方式。数据来自 `docs/migration_schema.md`(JSON),行为逻辑需按本方案在 GDScript 中重写。

## 1. 总体架构

```
Godot 项目
├── res://data/            # 转换后的 JSON(由转换器生成,只读)
├── res://core/            # 引擎无关的核心系统(GDScript)
│   ├── combat/            # 战斗系统
│   ├── input/             # 输入缓冲/指令序列识别
│   ├── stage/             # 关卡/生成
│   └── ui/                # HUD/菜单
└── res://actors/          # 角色场景(加载 JSON + 动画)
```

## 2. 核心系统映射表

| SOR2XCombo 系统 | OpenBOR 实现(已核实) | Godot 映射 | 备注 |
|---|---|---|---|
| 连段/取消 | `cancel` 行 + `atchain` + animationscript 的 main_cancel.c | 状态机 `CharacterStateMachine` + `CancelTable`(JSON cancels 字段) | 每 anim 一个状态;cancels 表驱动派生 |
| 弹反 | didblock/main.c(防御瞬间按前) | `BlockState.parry_window` + 计时器 | 弹反奖励(counterAttackReward)读全局配置 |
| 空连 Juggle | `jugglepoints`/`jugglecost` + getentityvar("tjug") | `JuggleComponent`(实体变量 juggle_points) | JSON juggle_points + jugglecost 已带 |
| 崩地 OTG | takedamage/main.c `otg()`(FALL/BURN/SHOCK 动画中扣点) | `OtgComponent`(受击时若动画为 fall/burn/shock 且 frame≥1 则扣点) | 逻辑已核实,直接翻译 |
| Rush Heat | ondoattack/main.c `rushHeat()`(rush_count ≥ 阈值 → invinc) | `ComboManager.rush_count` + 全局配置 rushHeat | 攻击命中时检查 |
| Last Chance | takedamage/main.c `lastChance()`(致命伤害+空血+满防 → 回血) | `DamagePipeline.last_chance()` | 条件:lethal && hp<10%max && gp≥50%max,或 lethal && hp<recoverRate && gp=100%;已核实 |
| 防御槽 | guardpoints/guardrate + didblock | `GuardComponent`(gp/max_gp/回复) | guardrate 回复速率 |
| 能量/MP | mp/mprate + addMp() | `EnergyComponent` | 攻击/被击/弹反回复 |
| 难度联动预设 | main_savecfg.c `applyDifficultyPreset()` | `DifficultyPreset`(Resource 表) | Normal/Hard/Mania 三档已提取 |
| 敌人 AI | think/main.c + key/*.c | `EnemyAI`(状态机:追击/攻击/防御/闪避) | 需重写,参考行为规则 |
| 随机 Boss | onspawn/main.c spawn | `StageDirector.random_boss_pool` | 每小关随机 Boss |

## 3. 状态机设计(角色)

```
CharacterState (Resource)
├── anim_name          # 对应 JSON anims 键
├── frames[]           # 帧数据(精灵/判定框/攻击框)
├── cancels[]          # 可取消到哪些状态
├── enter/exit hooks   # @cmd 行为钩子(GDScript 手动实现)
└── physics            # 速度/重力/位移
```

- 攻击框用 `Area2D` + `CollisionShape2D`,在帧内按 JSON bbox/attack 数据动态启用
- 帧推进用 `AnimationPlayer`(导入 PNG 序列)或 `SpriteFrames`;帧事件(攻击框激活、音效)用 `AnimationPlayer.call_method` 或帧回调
- 关键:OpenBOR `delay` 单位厘秒,JSON 已转毫秒;`attack` 判定框坐标相对帧左上角,需按精灵 offset 换算

## 4. 输入系统

- OpenBOR `com` 指令序列(`d f a2`、`f f a2`、`a2 + s`)→ Godot `InputBuffer`(记录最近 N 帧输入,匹配指令表)
- 指令表 = JSON commands 字段
- 斜跳/受身/投技等复合输入按 README 出招表实现

## 5. 数值来源(无需转换,直接提取)

- `data/scripts/attributes.h`:角色五维属性(Skill/Power/Speed/Jump/Energy)与平衡参数(hBase/sBase/jBase 等)
- `data/scripts/keyall/main_savecfg.c applyDifficultyPreset()`:三档难度预设(已核实:normal=lastChance 33%/rushHeat 5/juggle unlimited/otg unlimited;hard=25%/7/40/6;mania=20%/9/30/4 + blockCost 1 + smarterEnemy on)
- 关卡数据:`levels/*.txt` → levels.json(低优先)

## 6. 行为层取舍

| 行为 | 处理 |
|---|---|
| `@cmd` 约 100 个自定义函数 | 按语义分类重写:位移类(dasher/jump/toss)→ 物理组件;状态类(invinc/setidle)→ 状态机;生成类(spawn*)/音效类(sample*)/特效类(afterImage)→ 各自系统 |
| 47k 行回调脚本(didhit/takedamage/think 等) | 不迁移,按上表系统规则重写 |
| 动画数据(txt 中 frame/delay/bbox/attack) | 全部自动转换,零手工 |
