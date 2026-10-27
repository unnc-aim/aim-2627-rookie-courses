# S39 稳定过滤

Lesson 1 · Chapter 06 · 数组、std::array 与范围遍历

## 题目

输入 n 个整数，按原顺序输出非负元素，每行一个。n≤1000。

## 样例输入

```text
4 -2 0 4 -1
```

## 样例输出

```text
0
4
```

## 逐步推导

只在非负条件成立时追加到结果，不排序、不倒序，零也保留。

## 关键规则与边界

结果顺序与输入一致，这就是稳定过滤。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <vector>

int main() {
    int n = 0, x = 0;
    std::cin >> n;
    std::vector<int> valid;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (x >= 0)
            valid.push_back(x);
    }
    for (int v : valid)
        std::cout << v << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
