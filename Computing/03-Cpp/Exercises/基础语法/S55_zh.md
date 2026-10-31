# S55 递归阶乘

第 1 课 · 1.8 · 函数——让计算有明确的输入和输出

## 题目

输入 n∈[0,20]，递归计算 n!，返回 unsigned long long。

## 样例输入

```text
5
```

## 样例输出

```text
120
```

## 逐步推导

n<=1 时返回 1，其余返回 n 乘上规模减一的调用结果。

## 关键规则与边界

先定义递归终止条件。输入上限 20 保证结果可表示。

## 完整单文件参考程序

```cpp
#include <iostream>

unsigned long long factorial(int n) {
    return n <= 1 ? 1ULL : static_cast<unsigned long long>(n) * factorial(n - 1);
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << factorial(n) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
