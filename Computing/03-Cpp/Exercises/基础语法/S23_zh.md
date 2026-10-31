# S23 闰年判断

第 1 课 · 1.3 · 把 Python 的条件判断迁移过来

## 题目

输入 [1,9999] 年份，符合 Gregorian 闰年规则输出 LEAP，否则 COMMON。

## 样例输入

```text
1900
```

## 样例输出

```text
COMMON
```

## 逐步推导

把能被 400 整除与能被 4 但不能被 100 整除两种情况作逻辑或。

## 关键规则与边界

能被 100 整除的世纪年，还必须能被 400 整除。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    int y = 0;
    std::cin >> y;
    bool leap = y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
    std::cout << (leap ? "LEAP" : "COMMON") << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
