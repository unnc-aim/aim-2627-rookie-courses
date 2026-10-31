# O36 独占所有权转移

第 2 课 · 2.8 · 动态对象、独占所有权与异常清理

## 题目

make_unique 创建值为 7 的整数，将 a 移动给 b，输出 a 是否为空与 `*b`。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
true 7
```

## 逐步推导

移动只留下一个拥有者，源指针只能检查空值，不能解引用。

## 关键规则与边界

unique_ptr 不可复制，移动后源 unique_ptr 保证为空。普通容器移动后状态不应类推为必空。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <memory>
#include <utility>

// std::unique_ptr and std::move come from the standard library.

int main() {
    std::unique_ptr<int> a = std::make_unique<int>(7);
    std::unique_ptr<int> b = std::move(a);
    std::cout << std::boolalpha << (a == nullptr) << ' ' << *b << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
