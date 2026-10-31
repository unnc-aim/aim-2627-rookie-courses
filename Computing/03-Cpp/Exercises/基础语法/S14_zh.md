# S14 欧氏距离

第 1 课 · 1.2 · 为什么要写类型，算术结果为什么会变？

## 题目

输入点 x、y，输出它到原点的距离，保留两位小数。

## 样例输入

```text
3 4
```

## 样例输出

```text
5.00
```

## 逐步推导

读入两个 double，调用 hypot(x,y)，不把距离提前转成整数。

## 关键规则与边界

hypot 表达距离计算，也比直接 x*x+y*y 更能避免中间溢出。

## 完整单文件参考程序

```cpp
#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double x = 0.0, y = 0.0;
    std::cin >> x >> y;
    std::cout << std::fixed << std::setprecision(2) << std::hypot(x, y) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
