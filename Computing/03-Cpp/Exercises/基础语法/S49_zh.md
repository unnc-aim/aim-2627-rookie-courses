# S49 返回值与参数

第 1 课 · 1.8 · 函数——让计算有明确的输入和输出

## 题目

读取两个 [-1000,1000] 整数，调用 add 返回和并输出。

## 样例输入

```text
4 5
```

## 样例输出

```text
9
```

## 逐步推导

main 负责输入输出，add 只计算和；记录形参值与返回值，不混淆打印。

## 关键规则与边界

形参是函数内部变量，return 把结果交给调用者。

## 完整单文件参考程序

```cpp
#include <iostream>

int add(int a, int b) { return a + b; }

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << add(a, b) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
