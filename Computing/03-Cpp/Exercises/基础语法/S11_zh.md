# S11 三次测量平均值

Lesson 1 · Chapter 04 · 运算符的逐步计算

## 题目

输入三个 [-1000,1000] 整数，输出平均值，保留两位小数。

## 样例输入

```text
1 2 3
```

## 样例输出

```text
2.00
```

## 逐步推导

三数先求和，再除以 3.0；格式控制只改变显示，不改变平均值计算。

## 关键规则与边界

3.0 使表达式采用浮点除法。

## 完整单文件参考程序

```cpp
#include <iomanip>
#include <iostream>

int main() {
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::cout << std::fixed << std::setprecision(2) << (a + b + c) / 3.0 << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
