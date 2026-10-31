# S36 索引合法性

第 1 课 · 1.5 · Python 的 list 到了 C++，该用什么？

## 题目

固定数组 {10,20,30}，读取有符号索引，合法输出元素，否则 INVALID。

## 样例输入

```text
-1
```

## 样例输出

```text
INVALID
```

## 逐步推导

负下标和不小于长度的下标都先拒绝，合法后才读取元素。

## 关键规则与边界

先判负再转无符号，[] 不自动检查边界，at 会抛出异常。

## 完整单文件参考程序

```cpp
#include <array>
#include <iostream>

int main() {
    std::array<int, 3> a = {10, 20, 30};
    int index = 0;
    std::cin >> index;
    if (index < 0 || index >= static_cast<int>(a.size()))
        std::cout << "INVALID\n";
    else
        std::cout << a.at(index) << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
