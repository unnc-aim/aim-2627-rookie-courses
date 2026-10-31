# S18 闭区间判断

第 1 课 · 1.3 · 把 Python 的条件判断迁移过来

## 题目

输入速度，位于 [-3,3] 输出 SAFE，其余 UNSAFE。

## 样例输入

```text
-3
```

## 样例输出

```text
SAFE
```

## 逐步推导

上下界分别判断，使用逻辑与要求同时满足，两个端点都合法。

## 关键规则与边界

不能写 -3 <= speed <= 3，它会把前一次比较的 bool 再与 3 比较。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    double speed = 0.0;
    std::cin >> speed;
    std::cout << (speed >= -3 && speed <= 3 ? "SAFE" : "UNSAFE") << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
