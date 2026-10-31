# O19 vector 保存对象

第 2 课 · 2.3 · 怎样使用和传递对象：const、this、复制与引用

## 题目

Unit(id) 构造对象，把 2、7 两对象 emplace_back 到 vector，按 const 引用遍历输出 id。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
2
7
```

## 逐步推导

先完成两个追加，再遍历；打印期间不继续增长容器。

## 关键规则与边界

vector 扩容可能使指向元素的引用和指针失效，不保存长期元素地址。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <vector>

class Unit {
    int id_;

  public:
    explicit Unit(int id) : id_(id) {}
    int id() const { return id_; }
};

int main() {
    std::vector<Unit> units;
    units.emplace_back(2);
    units.emplace_back(7);
    for (const Unit & u : units)
        std::cout << u.id() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
