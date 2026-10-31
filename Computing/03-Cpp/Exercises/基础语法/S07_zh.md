# S07 命名空间同名变量

第 1 课 · 1.1 · Python 和 C++ 的程序分别怎样跑起来？

## 题目

aim::speed 为 3，sim::speed 为 8，输出二者，不使用 using namespace。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
3 8
```

## 逐步推导

定义两组同名变量，用各自命名空间前缀区分，不建立另一组局部副本。

## 关键规则与边界

限定名明确名字来源，头文件中尤其避免全局 using namespace。

## 完整单文件参考程序

```cpp
#include <iostream>

namespace aim {
int speed = 3;
}
namespace sim {
int speed = 8;
}

int main() {
    std::cout << aim::speed << ' ' << sim::speed << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
