# S45 ASCII 小写转大写

第 1 课 · 1.6 · 字符串、字符，以及“读一个词”和“读一整行”

## 题目

输入一行 ASCII 文本，仅把 a..z 转为 A..Z。

## 样例输入

```text
aim-07
```

## 样例输出

```text
AIM-07
```

## 逐步推导

遍历引用到每个 char，只修改落在小写字母区间的值。

## 关键规则与边界

本题显式限定 ASCII，不宣称这个规则支持所有语言。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (char &c : s)
        if (c >= 'a' && c <= 'z')
            c = char(c - 'a' + 'A');
    std::cout << s << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
