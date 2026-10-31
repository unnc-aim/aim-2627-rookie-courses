# S61 指向 const 的指针

第 1 课 · 1.10 · 指针——保存地址的变量，以及对象何时还有效

## 题目

a=3、b=7，const `int*` p 先指向 a 后指向 b，逐行输出解引用值。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
3
7
```

## 逐步推导

重定向修改的是 p 保存的地址，两次打印读取不同目标，目标本身不变。

## 关键规则与边界

`const int*` 允许重定向 p，但不能通过 p 修改对象。`int* const` 则固定指针本身。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int a = 3, b = 7;
    const int *p = &a;
    std::cout << *p << '\n';
    p = &b;
    std::cout << *p << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
