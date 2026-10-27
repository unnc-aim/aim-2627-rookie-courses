# S28 整数各位和

Lesson 1 · Chapter 05 · 条件与 for 循环

## 题目

输入 [0,10^9] 整数，输出十进制各位数字之和。

## 样例输入

```text
507
```

## 样例输出

```text
12
```

## 逐步推导

反复用余数取末位、整除去末位；零输入也执行一次但累计仍为零。

## 关键规则与边界

do-while 至少执行一次，因此输入 0 也有清晰语义。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int n = 0, sum = 0;
    std::cin >> n;
    do {
        sum += n % 10;
        n /= 10;
    } while (n != 0);
    std::cout << sum << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
