# S41 字符串长度与字符

Lesson 1 · Chapter 07 · 字符串的查、改、增、删

## 题目

输入一行 ASCII 文本，输出长度，非空时再输出首尾字符，空行只输出 0。

## 样例输入

```text
robot
```

## 样例输出

```text
5
r t
```

## 逐步推导

先读整行并输出长度，只有非空时才调用 front 与 back。

## 关键规则与边界

string::size 统计 char 数量。UTF-8 中文的字节数不等于汉字数。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << s.size() << '\n';
    if (!s.empty())
        std::cout << s.front() << ' ' << s.back() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
