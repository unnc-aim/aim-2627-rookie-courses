# S78 丢帧告警

第 1 课 · 1.5 · Python 的 list 到了 C++，该用什么？

## 题目

输入 n 个递增时间戳，若相邻间隔>10 输出后一个时间戳，每行一个。n≥0，时间戳≤10^9。

## 样例输入

```text
4 0 10 25 26
```

## 样例输出

```text
25
```

## 逐步推导

i=0 只建立前一帧，后续每次比较间隔并更新 prev。

## 关键规则与边界

首帧没有前一帧，不参与间隔比较。恰好 10 不告警。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    long long prev = 0;
    for (int i = 0; i < n; ++i) {
        long long ts = 0;
        std::cin >> ts;
        if (i > 0 && ts - prev > 10)
            std::cout << ts << '\n';
        prev = ts;
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
