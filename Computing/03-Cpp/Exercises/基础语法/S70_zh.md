# S70 固定窗口均值

第 1 课 · 1.5 · Python 的 list 到了 C++，该用什么？

## 题目

输入 n≥k≥1 和 n 个整数，逐行输出每个长度 k 窗口均值，两位小数。n≤1000，元素绝对值≤1000。

## 样例输入

```text
3 2 1 3 5
```

## 样例输出

```text
2.00
4.00
```

## 逐步推导

累加新项，满窗后减去离开项，从第 k 项起输出均值。

## 关键规则与边界

窗口每次加入新值、删除旧值，总复杂度 O(n)。

## 完整单文件参考程序

```cpp
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (i >= k)
            sum -= a[i - k];
        if (i >= k - 1)
            std::cout << std::fixed << std::setprecision(2)
                      << static_cast<double>(sum) / k << '\n';
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
