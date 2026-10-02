# Python Lesson-1: 基础语法和数据类型

## 课程信息

- **课时**: 3 学时（含 1 小时背景知识，今年新增）
- **难度**: 入门级
- **前置要求**: 无编程经验要求

## 学习目标

完成本节课后，学员将能够：

1. 说清楚程序如何被翻译成机器码并交给 CPU 运行、低级语言和高级语言的区别
2. 打开并使用命令行和 VS Code 完成基本操作
3. 配置 Python 开发环境
4. 理解 Python 基本语法规则
5. 掌握 Python 基础数据类型
6. 进行基本的变量操作和运算
7. 处理简单的输入输出
8. 编写第一个 Python 程序

## 本课主线

这节课的终点是亲手写出一个人人都能用的**计算器**——但"能用的程序"是由一串更小的需求堆出来的：

| 你会有的需求 | 怎么做 |
| --- | --- |
| 明白程序到底怎么跑起来 | 第 0 部分：背景知识 |
| 跑起来第一行代码 | 需求 1 |
| 写出别人看得懂的代码 | 需求 2 |
| 在程序里装下血量、名字、真假 | 需求 3 |
| 算伤害、比大小、下判断 | 需求 4 |
| 跟用程序的人对话 | 需求 5 |
| 把零件全部拼起来 | 需求：计算器 |

## 课程大纲

### 第 0 部分：背景知识（60 分钟，今年新增）

#### 0.1 计算机是怎么运行程序的

- 程序、指令与机器码
- 可执行程序（`.exe` / ELF）的本质：加载进内存，CPU 逐条执行

#### 0.2 低级语言和高级语言

- 机器码、汇编（低级）与 C / C++ / Python（高级）
- 编译 vs 解释：C 编译成可执行文件，Python 逐行解释执行
- 战队中的取舍：C++ 跑得快，Python 写得快

#### 0.3 命令行

- 命令行的历史：电传打字机、字符终端（VT100）到今天的终端窗口，以及 shell 的概念
- GUI 与 CLI；程序员为什么离不开命令行
- 打开 PowerShell / Terminal，会用 `ls`(`dir`)、`cd`、`clear`(`cls`)、`python --version`
- 衔接 `02-Linux` 课程

#### 0.4 VS Code

- 编辑器、IDE 与扩展生态
- 界面五件套、命令面板 `Ctrl+Shift+P`、集成终端 `` Ctrl+` ``

#### 0.5 Python 本身

- 历史（1989 / Guido van Rossum / Monty Python）与定位
- 解释型、动态类型、跨平台；课程使用 Python 3.12
- 在 Robotics 中的应用场景

### 需求 1：跑起来第一行代码（30 分钟）

#### 1.1 为什么是 Python

- Python 的历史和特点
- Python 的应用领域
- 在 Robotics 中的应用场景

#### 1.2 开发环境配置

- Python 安装和版本选择
- VS Code 配置
- Python 扩展插件安装
- 第一个"Hello World"程序

```python
print("Hello, RoboMaster!")
```

#### 1.3 Python 交互模式

- REPL 环境的使用
- IPython 介绍
- Jupyter Notebook 基础

### 需求 2：写出别人看得懂的代码（20 分钟）

#### 2.1 怎么写才整齐——缩进、注释与 PEP 8

- PEP 8 编码规范
- 缩进和代码块
- 注释的编写

```python
# 这是单行注释
"""
这是多行注释
用于详细说明
"""

def greet_robot(name):
    """问候机器人的函数"""
    print(f"Hello, {name}!")
```

#### 2.2 给东西起名字——标识符和关键字

- 变量命名规则
- Python 关键字
- 命名约定

### 需求 3：在程序里装下机器人世界的信息（40 分钟）

#### 3.1 记数量：血量与电压——数字类型

```python
# 整数
robot_id = 42
hero_hp = 600  # 英雄机器人血量较厚
infantry_hp = 200  # 步兵机器人标准血量

# 浮点数
battery_voltage = 12.5
distance = 3.14159

# 复数（了解即可）
complex_num = 3 + 4j
```

#### 3.2 记文字：名字与状态——字符串类型

```python
# 字符串定义
robot_name = "Hero"  # 英雄机器人
team_name = 'AIM'

# 字符串操作
message = "Robot " + robot_name + " is ready!"
formatted_msg = f"Battery level: {battery_voltage}V"

# 字符串方法
print(robot_name.upper())
print(robot_name.lower())
print(len(team_name))
```

#### 3.3 记真假：能不能开火——布尔类型

```python
is_robot_active = True
has_ammunition = False

# 布尔运算
can_shoot = is_robot_active and has_ammunition
```

#### 3.4 让信息互换格式——类型转换

```python
# 显式类型转换
score_str = "95"
score_int = int(score_str)
score_float = float(score_str)

# 隐式类型转换
result = 10 + 3.5  # 结果为浮点数
```

### 需求 4：算伤害、比大小、下判断（20 分钟）

#### 4.1 怎么算——算术运算符

```python
a = 10
b = 3

print(a + b)    # 加法: 13
print(a - b)    # 减法: 7
print(a * b)    # 乘法: 30
print(a / b)    # 除法: 3.333...
print(a // b)   # 整除: 3
print(a % b)    # 取余: 1
print(a ** b)   # 幂运算: 1000
```

#### 4.2 怎么比——比较运算符

```python
x = 5
y = 10

print(x == y)   # False
print(x != y)   # True
print(x < y)    # True
print(x > y)    # False
print(x <= y)   # True
print(x >= y)   # False
```

#### 4.3 怎么组合条件——逻辑运算符

```python
a = True
b = False

print(a and b)  # False
print(a or b)   # True
print(not a)    # False
```

### 需求 5：跟用程序的人对话（15 分钟）

#### 5.1 把结果讲给人听——print()

```python
# 基本输出
print("Hello World")

# 多个参数
print("Robot ID:", robot_id)

# 格式化输出
print(f"英雄机器人{robot_name}的血量是{hero_hp}HP")

# 控制输出格式
print("A", "B", "C", sep="-")  # A-B-C
print("Loading", end="...")    # 不换行
```

#### 5.2 听人说话——input()

```python
# 基本输入
user_name = input("请输入你的姓名: ")

# 类型转换输入
age = int(input("请输入年龄: "))
height = float(input("请输入身高(米): "))

print(f"你好 {user_name}, 你今年 {age} 岁，身高 {height} 米")
```

### 终极需求：把零件拼成计算器（15 分钟）

#### 项目：简单计算器（直算版）

用今天攒下的零件——input / float / 算术运算符 / f-string——做出你的第一台计算器：输入两个数，一次算出全部七种运算的结果。

```python
# Lesson-1 直算版：只用已学的零件
num1 = float(input("请输入第一个数字: "))
num2 = float(input("请输入第二个数字: "))

print(f"{num1} + {num2} = {num1 + num2}")
print(f"{num1} - {num2} = {num1 - num2}")
print(f"{num1} * {num2} = {num1 * num2}")
print(f"{num1} / {num2} = {num1 / num2}")
print(f"{num1} // {num2} = {num1 // num2}")
print(f"{num1} % {num2} = {num1 % num2}")
print(f"{num1} ** {num2} = {num1 ** num2}")
```

> 想让它只算你选的运算、除零时不崩溃？这需要条件语句和异常处理——Lesson-2 的零件。**课后作业 1** 就是学完 Lesson-2 后回来把它升级成"选运算 + 容错"的版本。

## 课堂练习

### 练习 1：个人信息收集器

编写程序收集用户的基本信息并格式化输出：

- 姓名、年龄、专业、兴趣爱好
- 使用 f-string 格式化输出

### 练习 2：单位转换器

编写程序实现基本单位转换：

- 摄氏度转华氏度
- 米转换为英尺
- 公斤转换为磅

### 练习 3：机器人状态检查器

模拟机器人状态检查：

- 输入机器人类型（Hero/Infantry/Engineer）
- 输入当前血量，判断血量状态
- 根据机器人类型判断是否可以攻击
- 输出机器人整体状态

## 课后作业

### 作业 1：增强计算器

在课堂项目基础上增加功能：

1. 支持连续计算
2. 添加更多运算符（如求余、幂运算）
3. 增加计算历史记录
4. 优化用户界面和错误处理

### 作业 2：个人名片生成器

编写程序生成 ASCII 艺术风格的个人名片：

- 包含姓名、联系方式、技能等信息
- 使用字符画装饰
- 支持不同的名片样式选择

## 学习检查点

完成本节课后，请确保你能够：

- [ ] 独立安装和配置 Python 开发环境
- [ ] 理解 Python 基本语法规则和代码风格
- [ ] 熟练使用各种数据类型和运算符
- [ ] 编写包含输入输出的基本程序
- [ ] 调试简单的语法错误
- [ ] 完成简单计算器项目

## 下节课预告

### Lesson-2: 数据结构和控制流程

- 学习列表、字典等复合数据类型
- 掌握条件语句和循环语句
- 开始函数式编程思维
- 项目：学生成绩管理系统

## 扩展阅读

- [Python 官方教程 - 第 3 章](https://docs.python.org/3/tutorial/introduction.html)
- [PEP 8 编码规范](https://www.python.org/dev/peps/pep-0008/)
- [Python 数据类型详解](https://docs.python.org/3/library/stdtypes.html)
