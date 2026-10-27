# S05 数字之后读取整行

Lesson 1 · Chapter 03 · 输入、变量与输出格式

## 题目

先读编号，再读下一整行名称。名称允许空格但不含前导空格。

## 样例输入

```text
7
AIM Sentry
```

## 样例输出

```text
7:AIM Sentry
```

## 逐步推导

先完成整数读取，再消费剩余前导空白，最后读取名称整行。

## 关键规则与边界

std::ws 消费全部前导空白，若空名称有意义，应改为 ignore 后 getline。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

int main() {
    int id = 0;
    std::string name;
    std::cin >> id;
    std::getline(std::cin >> std::ws, name);
    std::cout << id << ':' << name << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
