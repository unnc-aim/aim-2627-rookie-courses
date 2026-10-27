# S64 非拥有指针区间

Lesson 2 · Chapter 02 · 引用、地址与指针

## 题目

sum_span(p,n) 对 n 个元素求和，n=0 时允许 p=nullptr；演示数组与空区间。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
12 0
```

## 逐步推导

长度为零时循环不进入，所以无需解引用空指针；否则只访问 0..n-1。

## 关键规则与边界

指针没有自带长度。n>0 时调用者必须保证至少有 n 个有效元素。

## 完整单文件参考程序

```cpp
#include <cstddef>
#include <iostream>

long long sum_span(const int *p, std::size_t n) {
    long long total = 0;
    for (std::size_t i = 0; i < n; ++i)
        total += p[i];
    return total;
}

int main() {
    int a[] = {2, 4, 6};
    std::cout << sum_span(a, 3) << ' ' << sum_span(nullptr, 0) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
