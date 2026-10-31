# S20 短路保护除法

第 1 课 · 1.3 · 把 Python 的条件判断迁移过来

## 题目

输入 a、b，b 为 0 输出 INVALID，否则输出整数商是否大于 2，使用 boolalpha。

## 样例输入

```text
5 0
```

## 样例输出

```text
INVALID
```

## 逐步推导

分支先判断 b，成功路径才计算商；不把非法路径的临时值用于输出。

## 关键规则与边界

先排除零除数。不可先求商再验证 b。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    if (b == 0)
        std::cout << "INVALID\n";
    else
        std::cout << std::boolalpha << (a / b > 2) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
