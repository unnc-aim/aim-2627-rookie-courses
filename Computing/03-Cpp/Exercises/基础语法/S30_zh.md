# S30 素数判断

第 1 课 · 1.4 · 循环、输入结束与不断变化的状态

## 题目

输入 [0,10^9] 整数，素数输出 YES，否则 NO。

## 样例输入

```text
97
```

## 样例输出

```text
YES
```

## 逐步推导

先用 n>=2 排除特殊值，再找不超过平方根的因子，找到即可终止。

## 关键规则与边界

d<=n/d 避免 d*d 溢出。0 和 1 都不是素数。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    bool prime = n >= 2;
    for (int d = 2; prime && d <= n / d; ++d) {
        if (n % d == 0)
            prime = false;
    }
    std::cout << (prime ? "YES" : "NO") << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
