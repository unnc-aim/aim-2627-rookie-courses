# S48 字符串回文

第 1 课 · 1.6 · 字符串、字符，以及“读一个词”和“读一整行”

## 题目

输入一行 ASCII 文本，逐字节判断是否回文，空串算回文，输出 YES 或 NO。

## 样例输入

```text
level
```

## 样例输出

```text
YES
```

## 逐步推导

每个左半位置与对称右半位置比较，有任何一对不等则结果为否。

## 关键规则与边界

循环只走一半，空串不进入循环，不会执行 size()-1。

## 完整单文件参考程序

```cpp
#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    bool yes = true;
    for (std::size_t i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - 1 - i])
            yes = false;
    std::cout << (yes ? "YES" : "NO") << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
