# S60 空指针保护

Lesson 2 · Chapter 02 · 引用、地址与指针

## 题目

safe_increment 接收可能为空的 `int*`，非空时加一。依次用 nullptr 和 &x（x=7）调用，输出 x。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
8
```

## 逐步推导

空指针调用不做任何写入；有效地址调用恰好增加一次。

## 关键规则与边界

空指针不能解引用，检查为空是调用前置条件的一部分。

## 完整单文件参考程序

```cpp
#include <iostream>

void safe_increment(int *p) {
    if (p != nullptr)
        ++*p;
}

int main() {
    int x = 7;
    safe_increment(nullptr);
    safe_increment(&x);
    std::cout << x << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
