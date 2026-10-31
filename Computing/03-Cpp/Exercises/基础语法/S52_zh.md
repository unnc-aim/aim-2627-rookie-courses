# S52 默认参数

第 1 课 · 1.8 · 函数——让计算有明确的输入和输出

## 题目

实现缩放函数 scale(value,factor=2)，读取 value，分别用默认倍数和 3 倍调用。范围≤1000。

## 样例输入

```text
4
```

## 样例输出

```text
8 12
```

## 逐步推导

第一次只提供 value 使用默认值，第二次显式提供 3，比较两次调用。

## 关键规则与边界

默认参数一般写在声明处，不在声明和定义处重复指定。

## 完整单文件参考程序

```cpp
#include <iostream>

int scale(int value, int factor = 2) { return value * factor; }

int main() {
    int value = 0;
    std::cin >> value;
    std::cout << scale(value) << ' ' << scale(value, 3) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
