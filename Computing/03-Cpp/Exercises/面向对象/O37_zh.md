# O37 Rule of Zero

第 2 课 · 2.5 · 对象何时结束，资源由谁清理？

## 题目

Log 包装 `vector<string>`，使用默认复制、析构，复制后只向 b 追加，输出 a 与 b 长度。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
1 2
```

## 逐步推导

让容器承担元素存储，默认复制后分别维护各自集合。

## 关键规则与边界

优先让标准库成员承担资源管理，避免自行编写裸 new/delete 的复制与析构。

## 完整单文件参考程序

```cpp
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Log {
    std::vector<std::string> data_;

  public:
    void add(std::string s) { data_.push_back(std::move(s)); }
    std::size_t size() const { return data_.size(); }
};

int main() {
    Log a;
    a.add("start");
    Log b = a;
    b.add("stop");
    std::cout << a.size() << ' ' << b.size() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
