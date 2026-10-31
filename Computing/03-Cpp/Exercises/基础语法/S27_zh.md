# S27 过滤与提前停止

第 1 课 · 1.4 · 循环、输入结束与不断变化的状态

## 题目

依次读取整数，负数跳过，0 结束，其余累加。

## 样例输入

```text
3 -2 4 0 9
```

## 样例输出

```text
7
```

## 逐步推导

先处理 0 以结束循环，再跳过负值，最后累加正值。

## 关键规则与边界

continue 跳到下一轮，break 退出当前循环。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int x = 0;
    long long total = 0;
    while (std::cin >> x) {
        if (x == 0)
            break;
        if (x < 0)
            continue;
        total += x;
    }
    std::cout << total << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
