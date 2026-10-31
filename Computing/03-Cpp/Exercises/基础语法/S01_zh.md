# S01 Hello 与退出码

第 1 课 · 1.1 · Python 和 C++ 的程序分别怎样跑起来？

## 题目

输出两行 AIM 和 C++17，正常结束程序。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
AIM
C++17
```

## 逐步推导

先确认程序只有一个 main；两个输出各带换行，return 只设置退出状态。

## 关键规则与边界

main 返回 0 表示正常结束。换行使用 \n。

## 完整单文件参考程序

```cpp
#include <iostream>

int main() {
    std::cout << "AIM\nC++17\n";
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
