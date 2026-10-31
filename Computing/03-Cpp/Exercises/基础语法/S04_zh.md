# S04 读取带空格的名称

第 1 课 · 1.6 · 字符串、字符，以及“读一个词”和“读一整行”

## 题目

读取一整行机器人名称，输出方括号包围的原文本。

## 样例输入

```text
AIM Sentry 07
```

## 样例输出

```text
[AIM Sentry 07]
```

## 逐步推导

把整行存入一个 string，而非只读第一个词；输出括号时不改变原文本。

## 关键规则与边界

getline 保留行内空格，不保留换行。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::getline(std::cin, name);
    std::cout << '[' << name << "]\n";
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
