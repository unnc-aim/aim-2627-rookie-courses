# S25 循环累加

第 1 课 · 1.4 · 循环、输入结束与不断变化的状态

## 题目

输入 n∈[0,10000]，用 for 计算 1..n 的和。

## 样例输入

```text
5
```

## 样例输出

```text
15
```

## 逐步推导

累加器在循环外置零，循环从 1 到 n，两端都包含。

## 关键规则与边界

n=0 时循环零次，初始累加值 0 就是正确答案。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    long long total = 0;
    for (int i = 1; i <= n; ++i)
        total += i;
    std::cout << total << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
