# S74 运行长度编码

Lesson 1 · Chapter 08 · 第一课整合与结构体预告

## 题目

输入一行 ASCII 字符串，把连续相同字符编码为字符:次数，每段一行，空串无输出。

## 样例输入

```text
aaabbc
```

## 样例输出

```text
a:3
b:2
c:1
```

## 逐步推导

i 固定一段的起点，j 找到首个不同字符，用 j-i 计数后令 i=j。

## 关键规则与边界

内循环终止后，[i,j) 恰好覆盖同一段。

## 完整单文件参考程序

```cpp
#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (std::size_t i = 0; i < s.size();) {
        std::size_t j = i + 1;
        while (j < s.size() && s[j] == s[i])
            ++j;
        std::cout << s[i] << ':' << j - i << '\n';
        i = j;
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
