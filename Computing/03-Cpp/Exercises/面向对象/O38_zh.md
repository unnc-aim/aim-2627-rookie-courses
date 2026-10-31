# O38 异常与析构清理

第 2 课 · 2.8 · 动态对象、独占所有权与异常清理

## 题目

Guard 构造输出 ACQUIRE，析构输出 RELEASE。在作用域内抛 runtime_error，外层捕获输出 CAUGHT。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
ACQUIRE
RELEASE
CAUGHT
```

## 逐步推导

先建立 Guard，再抛异常；展开先析构，控制到 catch 后才打印捕获信息。

## 关键规则与边界

异常离开作用域时，已完成构造的自动对象仍会析构，体现 RAII。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <stdexcept>

struct Guard {
    Guard() { std::cout << "ACQUIRE\n"; }
    ~Guard() { std::cout << "RELEASE\n"; }
};

int main() {
    try {
        Guard guard;
        throw std::runtime_error("demo");
    } catch (const std::runtime_error &) {
        std::cout << "CAUGHT\n";
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
