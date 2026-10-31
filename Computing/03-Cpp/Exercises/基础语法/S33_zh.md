# S33 array 初始化

第 1 课 · 1.5 · Python 的 list 到了 C++，该用什么？

## 题目

创建长度 5 的 `std::array<int,5>`，只显式填入 94、87、50，每行输出一个元素。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
94
87
50
0
0
```

## 逐步推导

前三项使用给定初值，其余值初始化为零；遍历总长度仍是五。

## 关键规则与边界

聚合初始化未指定元素按值初始化为 0。无初始化的局部整数数组不保证为 0。

## 完整单文件参考程序

```cpp
#include <array>
#include <iostream>

int main() {
    std::array<int, 5> scores = {94, 87, 50};
    for (int score : scores)
        std::cout << score << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
