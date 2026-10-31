# S65 结构体遥测帧

第 1 课 · 1.11 · 把相关字段组织成记录，并处理一批记录

## 题目

定义 Frame{id,hp,speed}，读取三个字段后输出 id:hp:speed，speed 保留一位。

## 样例输入

```text
7 80 1.5
```

## 样例输出

```text
7:80:1.5
```

## 逐步推导

先读入同一个 Frame 的三个字段，再按明确分隔格式输出。

## 关键规则与边界

struct 把一条记录的相关字段组合在一起，默认成员访问权限是 public。

## 完整单文件参考程序

```cpp
#include <iomanip>
#include <iostream>

struct Frame {
    int id = 0;
    int hp = 0;
    double speed = 0.0;
};

int main() {
    Frame frame = {};
    std::cin >> frame.id >> frame.hp >> frame.speed;
    std::cout << frame.id << ':' << frame.hp << ':' << std::fixed
              << std::setprecision(1) << frame.speed << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
