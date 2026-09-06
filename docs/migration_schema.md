# SOR2XCombo → Godot 迁移:数据 Schema 草案

> 本文档是迁移方案的一部分,定义 OpenBOR 角色 txt → 通用 JSON 的目标结构。
> 转换器为独立工具(建议 Python 3.10+ 标准库实现,无第三方依赖),输出 JSON 由 Godot 4.x 的 `ResourceLoader`/`JSON.parse_string()` 加载。

## 1. 顶层结构

```
chars.json
├── meta            # 转换器版本、源文件清单、校验和
└── characters      # 数组,每角色一个条目(一个 txt = 一个角色实体)
    ├── id          # 稳定 ID,如 "heroes/axel/axel"
    ├── name        # name 字段
    ├── type        # player/enemy/npc/boss 等(引擎 type 映射)
    ├── stats       # ##MAIN 头部数值字段
    ├── anims       # 动画字典 { animName: Anim }
    ├── commands    # com 指令序列(必杀技输入)
    └── behaviors   # 行为钩子引用(不转换,仅标记)
```

## 2. stats 字段映射(##MAIN 头部)

| OpenBOR 字段 | JSON 字段 | 类型 | 说明 |
|---|---|---|---|
| health | health | int | 生命上限 |
| mp / mprate | mp / mp_rate | int / float | 能量 / 回复速率 |
| offense | offense | float | 伤害修正(可带类型) |
| speed | speed | float | 移动速度 |
| jumpheight | jump_height | float | 跳跃高度 |
| antigravity | anti_gravity | float | 重力系数 |
| grabdistance / grabfinish | grab_distance / grab_finish | int / int | 抓取距离/完成方式 |
| jugglepoints | juggle_points | int | 可被空连次数 |
| guardpoints / guardrate | guard_points / guard_rate | int / int | 防御值 / 回复速率 |
| risetime / riseinv | rise_time / rise_inv | int / float | 起身时间/无敌 |
| makeinv | make_inv | string | 受击无敌参数 |
| atchain | at_chain | string | 普攻连段链 |
| weapons / weaploss | weapons / weapon_loss | string[] / int | 武器表 |
| modelflag / gfxshadow / dust | model_flag / gfx_shadow / dust | mixed | 特效参数 |

## 3. Anim 结构

```json
{
  "idle": {
    "loop": true,
    "start_frame": 0,
    "end_frame": -1,
    "frames": [
      {
        "sprite": "data/chars/heroes/axel/idle00.png",
        "delay_ms": 160,
        "offset": [62, 126],
        "bbox": [50, 55, 23, 74],
        "sound": null,
        "hitfx": null,
        "attack": null
      }
    ],
    "cancels": [
      { "start": 0, "end": 5, "hits": 0, "input": "a2", "target": "freespecial2" }
    ],
    "behaviors": ["@cmd looper 4 9"]
  }
}
```

- `delay_ms`:OpenBOR `delay` 单位是厘秒(1/100s),转换时 ×10 得毫秒
- `attack`:帧攻击框,见下节
- `cancels`:每 anim 的 `cancel` 行集合

## 4. attack 帧字段(十参数)

OpenBOR `attack {x} {y} {right} {down} {damage} {power} {block} {noflash} {pausetime} {z}`:

```json
{
  "x": 39, "y": 75, "w": 41, "h": 34,
  "damage": 4, "power": 1,
  "blockable": true, "no_flash": false,
  "pause_time": 20, "z": 12,
  "type": "NORMAL"     // attack# 编号 → 类型枚举
}
```

- `attack#` 编号(1-10)映射为 `type` 枚举,决定受击方 PAIN#/FALL#/DEATH# 反应
- `attack 0 0 0 0 0 0 0 0 0 0` 视为空攻击框(清理上一帧),保留原样
- `attackone`(0/1):攻击框一次性开关,写入 attack 帧对象 `one_shot` 字段

## 5. com 指令序列

```json
{
  "input": "d f a2",
  "target": "freespecial2"
}
```

输入记号映射:`u/d/f/b`(方向)、`a/a2/a3/a4`(攻击键)、`j`(跳)、`s`(特殊)、`+`(同帧多键)。

## 6. 行为钩子(不转换)

- `animationscript/didhitscript/onspawnscript/takedamagescript/...` 等 2789 处引用 → 写入 `behaviors` 标记(引用脚本路径),**不转换**
- `@cmd ...` 行 → 写入对应 anim 的 `behaviors` 数组,标注函数名与参数,由 Godot 端手动重写
- `com`/`cancel`/`attack` 等数据性命令 → 全部转换

## 7. 关卡/场景(另表,低优先)

关卡 txt 的 `spawn/coords/flip/map/bglayer/load/type/order/settime` 等命令 → 单独 levels.json,字段语义需结合 Godot TileMap/场景树映射(Phase 3 细化)。
