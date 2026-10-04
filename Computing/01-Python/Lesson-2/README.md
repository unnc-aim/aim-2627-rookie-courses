# Python Lesson-2: 数据结构和控制流程

## 课程信息

- **课时**: 2 学时
- **难度**: 初级
- **前置要求**: 完成 Lesson-1

## 学习目标

完成本节课后，学员将能够：

1. 熟练使用 Python 内置数据结构（列表、元组、字典、集合）
2. 掌握条件语句和循环语句的使用
3. 理解函数的定义和调用
4. 编写更复杂的程序逻辑
5. 完成学生成绩管理系统项目

## 本课主线

主线项目是**学生成绩管理系统**——管理"全班 30 个人 × 4 门课"会逼出这节课的全部新知识：

| 你会有的需求 | 怎么做 |
| --- | --- |
| 把一串成绩一口气记下来、逐个翻 | 需求 1：列表 / 元组 / 字典 / 集合 |
| 不同分数给不同评语 | 需求 2：条件 |
| 对每个人都做一遍同样的统计 | 需求 2：循环 |
| 同一段逻辑不想抄三遍 | 需求 3：函数 |
| 把它们拼成能交互的系统 | 需求：成绩管理系统 |

## 课程大纲

### 需求 1：把一批数据装进一个名字——复合数据类型（45 分钟）

#### 1.1 按顺序记一串——列表 (List)

```python
# 列表创建和基本操作
robots = ["Hero", "Infantry", "Engineer"]  # 去掉Drone，因为我们重点关注这三种
robot_hp = [600, 200, 250]  # 对应的血量：英雄、步兵、工程

# 列表访问和修改
print(robots[0])        # Hero
robots[1] = "Infantry-1"
print(robots)           # ['Hero', 'Infantry-1', 'Engineer']

# 列表方法
robots.append("Sentry")         # 添加元素
robots.insert(1, "Infantry-2")  # 插入元素
removed = robots.pop()          # 删除并返回最后一个元素
robots.remove("Engineer")       # 删除指定元素

# 列表切片
print(robots[1:3])      # 切片操作
print(robots[:2])       # 前两个元素
print(robots[::2])      # 每隔一个元素
```

**列表应用场景：**

- 存储机器人队列
- 记录比赛得分
- 管理任务列表

#### 1.2 定了就不许改——元组 (Tuple)

```python
# 元组创建
robot_position = (100, 200)  # 机器人坐标
team_info = ("RoboMaster", 2024, "Champion")

# 元组解包
x, y = robot_position
team_name, year, achievement = team_info

# 元组应用
def get_robot_status():
    return "Active", 12.5, 95  # 返回多个值

status, voltage, health = get_robot_status()
```

#### 1.3 按名字查，不数下标——字典 (Dict)

```python
# 字典创建和操作
robot_config = {
    "name": "Hero",
    "type": "Combat",
    "hp": 400,
    "speed": 3.0,
    "weapons": ["17mm", "42mm"]
}

# 字典访问和修改
print(robot_config["name"])
robot_config["hp"] = 350
robot_config["armor"] = "Level-3"

# 字典方法
print(robot_config.keys())      # 获取所有键
print(robot_config.values())    # 获取所有值
print(robot_config.items())     # 获取键值对

# 安全访问
armor = robot_config.get("armor", "None")
```

**字典应用场景：**

- 机器人配置参数
- 用户信息存储
- 数据统计计数

#### 1.4 自动去重——集合 (Set)

```python
# 集合创建和操作
team_a_skills = {"Programming", "Mechanical", "Electronics"}
team_b_skills = {"Programming", "Vision", "Control"}

# 集合运算
common_skills = team_a_skills & team_b_skills     # 交集
all_skills = team_a_skills | team_b_skills        # 并集
unique_skills = team_a_skills - team_b_skills     # 差集

# 集合方法
team_a_skills.add("AI")
team_a_skills.remove("Mechanical")
```

### 需求 2：让程序自己拿主意、自己跑重复——控制流程（40 分钟）

#### 2.1 分岔：不同情况不同处理——条件

```python
# 基本if语句
robot_hp = 150

if robot_hp > 200:
    print("机器人状态良好")
elif robot_hp > 100:
    print("机器人状态一般")
else:
    print("机器人状态危险")

# 复杂条件判断
def check_robot_status(hp, armor, ammo):
    if hp <= 0:
        return "机器人已损坏"
    elif hp < 100 and armor < 50:
        return "危险状态，需要维修"
    elif ammo == 0:
        return "弹药耗尽"
    else:
        return "状态正常"

# 三元运算符
status = "在线" if robot_hp > 0 else "离线"
```

#### 2.2 重复：让机器干体力活——循环

##### **for 循环 - 遍历序列**

```python
# 遍历列表
robots = ["Hero", "Infantry", "Engineer"]
for robot in robots:
    print(f"检查机器人: {robot}")

# 遍历字典
robot_scores = {"Hero": 95, "Infantry": 87, "Engineer": 92}
for robot, score in robot_scores.items():
    print(f"{robot}: {score}分")

# range()函数
for i in range(5):          # 0到4
    print(f"Round {i + 1}")

for i in range(1, 11, 2):   # 1到10，步长为2
    print(i)                # 1, 3, 5, 7, 9
```

- **while 循环 - 条件循环**

```python
# 机器人移动模拟
position = 0
target = 100

while position < target:
    position += 10
    print(f"当前位置: {position}")

    if position >= target:
        print("到达目标位置")
        break

# 用户输入验证
while True:
    user_input = input("请输入机器人ID (1-6): ")
    if user_input.isdigit() and 1 <= int(user_input) <= 6:
        robot_id = int(user_input)
        break
    else:
        print("输入无效，请重新输入")
```

#### 急刹车与跳过——break / continue

```python
# break和continue
scores = [95, 67, 88, 45, 92, 73]

# 找到第一个不及格分数
for score in scores:
    if score < 60:
        print(f"发现不及格分数: {score}")
        break

# 只处理及格分数
total = 0
count = 0
for score in scores:
    if score < 60:
        continue
    total += score
    count += 1

average = total / count if count > 0 else 0
print(f"及格分数平均值: {average}")
```

### 需求 3：一段逻辑，到处复用——函数（25 分钟）

#### 3.1 定义自己的工具——函数与参数

```python
# 基本函数定义
def calculate_damage(attack_power, armor_defense):
    """计算伤害值"""
    damage = max(0, attack_power - armor_defense)
    return damage

# 默认参数
def create_robot(name, robot_type="Infantry", hp=200):
    """创建机器人"""
    robot = {
        "name": name,
        "type": robot_type,
        "hp": hp,
        "max_hp": hp
    }
    return robot

# 可变参数
def calculate_total_score(*scores):
    """计算总分"""
    return sum(scores)

def create_team(**members):
    """创建团队"""
    return members

# 函数调用示例
hero = create_robot("Hero-1", "Hero", 400)
total = calculate_total_score(95, 87, 92, 88)
team = create_team(captain="Alice", programmer="Bob", operator="Carol")
```

#### 3.2 局部变量和全局变量

```python
# 全局变量
GAME_VERSION = "2024"
team_score = 0

def update_score(points):
    """更新得分"""
    global team_score
    team_score += points
    return team_score

def get_game_info():
    """获取游戏信息"""
    local_info = f"当前版本: {GAME_VERSION}"
    return local_info
```

### 终极需求：学生成绩管理系统（20 分钟）

```python
class StudentGradeManager:
    """学生成绩管理系统"""

    def __init__(self):
        self.students = {}  # 存储学生信息

    def add_student(self, student_id, name):
        """添加学生"""
        if student_id not in self.students:
            self.students[student_id] = {
                "name": name,
                "grades": {}
            }
            print(f"学生 {name} 添加成功")
        else:
            print("学生ID已存在")

    def add_grade(self, student_id, subject, grade):
        """添加成绩"""
        if student_id in self.students:
            if 0 <= grade <= 100:
                self.students[student_id]["grades"][subject] = grade
                print(f"成绩添加成功")
            else:
                print("成绩必须在0-100之间")
        else:
            print("学生不存在")

    def calculate_average(self, student_id):
        """计算平均分"""
        if student_id in self.students:
            grades = self.students[student_id]["grades"]
            if grades:
                return sum(grades.values()) / len(grades)
            else:
                return 0
        return None

    def get_top_students(self, n=3):
        """获取前n名学生"""
        student_averages = []
        for student_id, info in self.students.items():
            avg = self.calculate_average(student_id)
            if avg is not None:
                student_averages.append((info["name"], avg))

        # 排序并返回前n名
        student_averages.sort(key=lambda x: x[1], reverse=True)
        return student_averages[:n]

    def display_all_students(self):
        """显示所有学生信息"""
        for student_id, info in self.students.items():
            name = info["name"]
            avg = self.calculate_average(student_id)
            print(f"ID: {student_id}, 姓名: {name}, 平均分: {avg:.2f}")

# 系统使用示例
def main():
    manager = StudentGradeManager()

    while True:
        print("\n=== 学生成绩管理系统 ===")
        print("1. 添加学生")
        print("2. 添加成绩")
        print("3. 查看平均分")
        print("4. 查看排名")
        print("5. 显示所有学生")
        print("0. 退出")

        choice = input("请选择操作: ")

        if choice == "1":
            student_id = input("请输入学生ID: ")
            name = input("请输入学生姓名: ")
            manager.add_student(student_id, name)

        elif choice == "2":
            student_id = input("请输入学生ID: ")
            subject = input("请输入科目: ")
            try:
                grade = float(input("请输入成绩: "))
                manager.add_grade(student_id, subject, grade)
            except ValueError:
                print("请输入有效的成绩")

        elif choice == "3":
            student_id = input("请输入学生ID: ")
            avg = manager.calculate_average(student_id)
            if avg is not None:
                print(f"平均分: {avg:.2f}")
            else:
                print("学生不存在")

        elif choice == "4":
            top_students = manager.get_top_students()
            print("前三名学生:")
            for i, (name, avg) in enumerate(top_students, 1):
                print(f"{i}. {name}: {avg:.2f}")

        elif choice == "5":
            manager.display_all_students()

        elif choice == "0":
            print("感谢使用！")
            break

        else:
            print("无效选择，请重新输入")

if __name__ == "__main__":
    main()
```

## 课堂练习

### 练习 1：数据结构操作

创建一个程序管理 RoboMaster 团队信息：

- 使用字典存储队员信息（姓名、专业、技能）
- 使用列表管理比赛历史记录
- 实现增删改查功能

### 练习 2：循环和条件综合

编写程序模拟机器人巡逻：

- 机器人在固定路径上移动
- 遇到障碍物时改变方向
- 记录移动轨迹和状态变化

### 练习 3：函数设计

设计一套机器人工具函数：

- 距离计算函数
- 角度转换函数
- 状态检查函数
- 参数验证函数

## 课后作业

### 作业 1：增强成绩管理系统

在课堂项目基础上添加功能：

1. 数据持久化（文件读写）
2. 成绩统计分析（最高分、最低分、分数分布）
3. 多科目成绩权重计算
4. 学生信息导入导出

### 作业 2：机器人队列管理系统

开发一个机器人任务队列管理程序：

- 任务优先级管理
- 机器人状态跟踪
- 任务分配算法
- 性能统计报告

## 学习检查点

完成本节课后，请确保你能够：

- [ ] 熟练使用列表、字典、元组、集合
- [ ] 编写复杂的条件判断逻辑
- [ ] 使用 for 和 while 循环处理数据
- [ ] 定义和调用带参数的函数
- [ ] 完成学生成绩管理系统项目
- [ ] 调试更复杂的程序错误

## 下节课预告

### Lesson-3: 面向对象编程和程序设计

- 学习类和对象的概念
- 掌握继承、封装、多态
- 异常处理和文件操作
- 模块、包与项目组织
- 项目：机器人控制系统模拟器

## 扩展阅读

- [Python 数据结构官方文档](https://docs.python.org/3/tutorial/datastructures.html)
- [Python 控制流程](https://docs.python.org/3/tutorial/controlflow.html)
- [Python 函数定义](https://docs.python.org/3/tutorial/controlflow.html#defining-functions)
