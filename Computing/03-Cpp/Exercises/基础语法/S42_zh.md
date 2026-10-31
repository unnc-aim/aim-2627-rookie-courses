# S42 查找子串

第 1 课 · 1.6 · 字符串、字符，以及“读一个词”和“读一整行”

## 题目

输入一行文本，再输入一行关键词，输出首次出现的下标，找不到输出 -1。

## 样例输入

```text
AIM Sentry
Sentry
```

## 样例输出

```text
4
```

## 逐步推导

原样保留查找返回类型；未找到单独输出 -1，找到则输出从零开始的位置。

## 关键规则与边界

npos 是特殊的 size_type 值，不应先窄化成 int 再判断。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

int main() {
    std::string text, key;
    std::getline(std::cin, text);
    std::getline(std::cin, key);
    std::string::size_type pos = text.find(key);
    if (pos == std::string::npos)
        std::cout << -1 << '\n';
    else
        std::cout << pos << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
