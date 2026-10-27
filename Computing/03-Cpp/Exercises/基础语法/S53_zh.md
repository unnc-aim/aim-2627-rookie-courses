# S53 函数重载

Lesson 2 · Chapter 01 · 函数：输入、计算与返回

## 题目

重载 label(int) 与 label(double)，分别返回 INT 和 DOUBLE，输出 label(3)、label(3.0)。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
INT DOUBLE
```

## 逐步推导

用整数字面量和 double 字面量分别调用，先确定实参类型再选择函数。

## 关键规则与边界

实参类型影响重载选择，仅返回类型不同不能构成重载。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>

std::string label(int) { return "INT"; }
std::string label(double) { return "DOUBLE"; }

int main() {
    std::cout << label(3) << ' ' << label(3.0) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
