# Computing 计算方向总览

## 适用对象

**控制组**、**导航组**、**算法组**成员共同学习路线

> 2627 学年起，控制（原电控）、导航、算法三个组为平行组，共用 `Computing/` 目录下的公共基础课程（`01`-`04`），分组后各自进入组目录学习专业内容。

## 学习资料

- Python 编程：[点击查看](./01-Python/README.md)
- Linux 基础：[点击查看](./02-Linux/README.md)
- Cpp 编程：[点击查看](./03-Cpp/README.md)
- ROS2 系统：[点击查看](./04-ROS2/README.md)
- 控制组学习路线：[点击查看](./Control/README.md)
- 导航组学习路线：[点击查看](./Navigation/README.md)
- 算法组学习路线：[点击查看](./Algorithm/README.md)

## 学习路径

```mermaid
graph TD
    A[Computing 计算方向] --> B[基础课程必修]
    A --> C[专业分组]
    A --> D[进阶内容]

    B --> E[Python 编程<br/>→ 01-Python/]
    B --> F[Linux 基础+进阶<br/>→ 02-Linux/]
    B --> G[Cpp 编程<br/>→ 03-Cpp/]
    B --> L[ROS2 系统<br/>→ 04-ROS2/]

    E --> E1[Lesson-1: 基础语法]
    E --> E2[Lesson-2: 数据结构]
    E --> E3[Lesson-3: 面向对象]

    F --> F1[Linux 系统基础]

    G --> G1[python内容迁移]

    L --> L1[Cpp版本教程]

    C --> H[Algorithm 算法组]
    C --> I[Control 控制组]
    C --> N[Navigation 导航组]

    H --> J[Vision 视觉算法<br/>→ Algorithm/]
    J --> J1[OpenCV 基础<br/>→ 05-OpenCV/]
    J --> J2[Aiming 自瞄系统<br/>→ Algorithm/Aiming/]
    J --> J3[Radar 雷达系统<br/>→ Algorithm/Radar/]

    N --> N1[路径规划算法]
    N --> N2[SLAM定位建图]
    N --> N3[运动控制]

    I --> I1[嵌入式系统开发]
    I --> I2[硬件接口设计]
    I --> I3[实时系统编程]

    D --> D1[多机协作算法]
    D --> D2[深度学习应用]
    D --> D3[系统集成与优化]
```

## 课程安排

### 第一阶段：基础能力建设 (6-7 周)

1. **Python 编程** (国庆 4 天特训) - 编程基础，为后续学习打下基础
2. **Linux 基础** (1 周) - Linux 环境熟悉，开发环境搭建
3. **Cpp 编程** （2 周）- 由 Python 转向 Cpp 编写
4. **ROS2 系统** (2 周) - 机器人框架基础

### 第二阶段：专业分组 (2-3 周)

根据兴趣和战队需求选择：

- **控制组** → 嵌入式、电机与底盘控制
- **导航组** → SLAM、路径规划、运动控制
- **算法组** → 视觉算法（自瞄 / 雷达方向）

### 第三阶段：项目实战 (2-4 周)

- 参与 RoboMaster 机器人项目开发
- 完成最终考核项目

## 培养目标

完成学习路线后，你将具备：

- 熟练的 Python 编程能力
- Linux 开发环境使用能力
- ROS2 机器人框架应用能力
- 专业方向的核心技能
- RoboMaster 比赛开发经验
