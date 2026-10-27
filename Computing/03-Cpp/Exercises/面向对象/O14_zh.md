# O14 引用访问与值访问

Lesson 2 · Chapter 06 · 实例、方法与乐队集合

## 题目

Buffer 包装 vector，copy() 返回副本，view() 返回 const 引用。修改副本首项为 9，输出 view 首项和副本首项。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
1 9
```

## 逐步推导

只修改独立副本，原对象的只读 view 仍观察到原始值。

## 关键规则与边界

返回引用避免复制，但引用不能比 Buffer 活得更久。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <vector>

class Buffer {
    std::vector<int> values_ = {1, 2};

  public:
    std::vector<int> copy() const { return values_; }
    const std::vector<int> &view() const { return values_; }
};

int main() {
    Buffer b;
    std::vector<int> c = b.copy();
    c[0] = 9;
    std::cout << b.view()[0] << ' ' << c[0] << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
