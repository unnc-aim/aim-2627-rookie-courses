# S71 时间戳去重

Lesson 1 · Chapter 08 · 第一课整合与结构体预告

## 题目

输入 n 条 ts、value，时间戳范围 [0,100]。每个时间戳仅保留首次记录，按输入顺序输出。

## 样例输入

```text
3 2 10 2 99 1 7
```

## 样例输出

```text
2 10
1 7
```

## 逐步推导

seen 初值全 false，首次出现先标记再输出，重复项不覆盖。

## 关键规则与边界

首次合法记录生效。有限键域可以用布尔数组实现 O(1) 查询。

## 完整单文件参考程序

```cpp
#include <array>
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::array<bool, 101> seen = {};
    for (int i = 0; i < n; ++i) {
        int ts = 0, value = 0;
        std::cin >> ts >> value;
        if (!seen[ts]) {
            seen[ts] = true;
            std::cout << ts << ' ' << value << '\n';
        }
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
