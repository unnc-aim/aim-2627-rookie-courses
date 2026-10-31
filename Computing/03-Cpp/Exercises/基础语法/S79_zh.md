# S79 Debug 循环边界

第 1 课 · 1.4 · 循环、输入结束与不断变化的状态

## 题目

修复求 n 个整数之和的旧代码：for(i=0;i<=n;++i)。输入 n≤1000，逐项读取合法整数。

## 样例输入

```text
3 1 2 3
```

## 样例输出

```text
6
```

## 逐步推导

循环次数必须恰为 n，改为 i<n，避免多读一个不存在的数。

## 关键规则与边界

<=n 会多读一次。调试时比较循环次数、输入数量与下标有效区间。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int value = 0;
        std::cin >> value;
        sum += value;
    }
    std::cout << sum << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
