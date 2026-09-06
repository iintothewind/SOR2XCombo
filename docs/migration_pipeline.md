# SOR2XCombo → Godot 迁移:导入管线

> 本文档定义素材与数值从 OpenBOR 项目进入 Godot 的落地路径。素材版权声明见 `SOR2XCombo.md`(素材非作者所有),**本方案默认不迁移素材,仅给出可复用的技术路径**;若作者自备版权素材,按此管线导入。

## 1. 管线总览

```
OpenBOR data/
├── chars/*/xxx.txt        → 转换器 → chars.json(已定义 schema)
├── chars/*/*.png          → [素材管线] → Godot SpriteFrames / AtlasTexture
├── sounds|voices/*.wav    → [音频管线] → .import(或转 .ogg)
├── music/*.ogg            → [音乐管线] → 直接导入(格式兼容)
├── levels/*.txt           → 转换器(低优先) → levels.json
└── scripts/*.c            → 不迁移(规则见 architecture 文档)
```

## 2. 图片素材(仅当版权允许)

现状核实:
- 8588 张 PNG,其中 8584 张为 **8-bit 调色板 PNG**(depth=8, ctype=3)
- 角色帧尺寸集中在 **(300×300)**(4726 张,主角/boss 帧)、**(480×272)**(1206 张,背景/全屏)
- 另有个别 32-bit(3 张)与灰度(1 张)

路径:
1. **批量转换 8-bit → 32-bit RGBA**:`ImageMagick` 或 Python Pillow 脚本,输出 `.png`(Godot 4 默认导入 RGBA8,调色板 PNG 也可直接导入,但转 RGBA 更稳)
2. **角色帧 → SpriteFrames**:按角色目录 + anim 名组织,`AnimationPlayer` 引用 `SpriteFrames`;或保留单帧 PNG + JSON 帧表,运行时 `Texture2D` 加载(数据驱动,推荐)
3. **判定框**:不依赖图片,由 JSON bbox/attack 数据在 `Area2D` 上动态生成 `CollisionShape2D`
4. **offset 换算**:OpenBOR `offset` 是精灵基点(脚底/阴影锚点),Godot 用 `Sprite2D.offset` 或 `centered=false` + position 换算,需在转换器里输出 `anchor` 字段(已在 schema 的 frames.offset 中保留)
5. **remap 换色**:OpenBOR `remap` 是运行时调色板映射 → Godot 用 `ShaderMaterial`(palette swap shader)或预生成变体贴图;素材量小(alter1-7),可预生成

## 3. 音频素材(仅当版权允许)

现状核实:
- 676 个 `.wav`:单声道 44100Hz/16-bit 为主,少量 22050Hz/8-bit(需转 16-bit)
- 92 个 `.ogg`:音乐(remake/remix/sor1/sor2x 各风格)
- 音量语义:OpenBOR 0-60,Godot 0-1(dB 或 linear),`playsample` 调用需换算

路径:
- `.wav` 统一转 16-bit/44100 或直接导入(Godot 支持 wav);`.ogg` 直接导入
- 用 `AudioStreamPlayer` 池替代 OpenBOR 的 64 通道 playsample
- `playmusic` 换轨 → `AudioStreamPlayer` + 曲目表(JSON)

## 4. 数值导入(零成本,直接提取)

| 来源 | 内容 | 落地 |
|---|---|---|
| `scripts/attributes.h` | 角色五维(Skill/Power/Speed/Jump/Energy)、平衡参数(hBase/sBase/jBase/sDif/jDif 等) | 手工转录为 `res://data/balance.tres` 或 JSON |
| `keyall/main_savecfg.c applyDifficultyPreset()` | 三档难度预设 | 手工转录为 `res://data/difficulty.tres`(已核实数值) |
| `keyall/main_savecfg.c defaultCfg()` | 菜单默认配置 | 同上,`settings.tres` |
| 角色 txt | 招式/帧/判定数据 | **自动转换**(转换器) |

## 5. 脚本逻辑导入(重写,不迁移)

- 47k 行 OpenBOR 脚本 → 按 `migration_architecture.md` 的系统映射重写为 GDScript
- 建议重写顺序(依赖驱动):
  1. `core/combat`(伤害管线:damageentity/hitDmg/combatDmg 语义)
  2. `core/input`(指令缓冲)
  3. 角色状态机 + 数据加载
  4. 防御/弹反/投技/受身
  5. Juggle/OTG/Rush Heat/Last Chance(纯规则,可最先做单元测试)
  6. 关卡/生成/随机 Boss
  7. 菜单/存档/难度联动
- 单元测试友好点:Juggle/OTG/Last Chance/Rush Heat 都是纯函数式规则(输入:状态+伤害,输出:状态变更),可用 GUT 直接测

## 6. 工具建议

- 转换器:Python 3.10+ 标准库(无第三方依赖),输出 JSON;测试用 2-3 个角色(axel/shiva/kun)做 golden 对比
- 8-bit PNG 转换:Pillow(或 ImageMagick)批处理脚本
- Godot 版本:4.x(建议 4.2+);导入用 `.tres` 或运行时 JSON 加载均可

## 7. 工作量估算(供规划参考)

| 项 | 量 | 估时 |
|---|---|---|
| 转换器(角色 txt → JSON) | 484 个 txt | 1-2 周 |
| 8-bit PNG 批转 + 帧表 | 8588 张 | 1-2 天(脚本) |
| 数值转录(五维/难度/默认配置) | 3 个表 | 0.5 天 |
| 核心战斗系统重写 | 见架构文档 | 4-8 周 |
| 角色行为重写(@cmd 100 函数) | 每角色 | 2-4 周/角色 |
| 关卡/菜单/存档 | — | 4-6 周 |
