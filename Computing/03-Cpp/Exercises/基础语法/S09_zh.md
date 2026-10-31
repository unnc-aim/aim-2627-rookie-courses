# S09 整数除法与转换

第 1 课 · 1.2 · 为什么要写类型，算术结果为什么会变？

## 题目

读取两个正整数 a、b，分别输出整数商和两位小数的实数商。

## 样例输入

```text
3 2
```

## 样例输出

```text
1 1.50
```

## 逐步推导

先保留整数商作对照；第二个表达式在除法前转换 a，再设置两位小数显示。

## 关键规则与边界

除法前转换一个操作数。static_cast<double>(a/b) 已经丢失小数。

## 完整单文件参考程序

```cpp
#include <iomanip>
#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << a / b << ' ' << std::fixed << std::setprecision(2)
              << static_cast<double>(a) / b << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
