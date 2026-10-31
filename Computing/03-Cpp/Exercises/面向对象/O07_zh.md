# O07 const 数据成员

第 2 课 · 2.2 · 构造对象时，就把它准备好

## 题目

Sensor 具有 const int `id_`，构造时初始化为 7，getter 输出编号。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
7
```

## 逐步推导

在冒号后给 `id_` 初值，不在函数体内尝试给常量成员赋值。

## 关键规则与边界

const 成员必须在初始化阶段获得值，不能留到构造函数体内赋值。

## 完整单文件参考程序

```cpp
#include <iostream>

class Sensor {
    const int id_;

  public:
    explicit Sensor(int id) : id_(id) {}
    int id() const { return id_; }
};

int main() {
    Sensor s(7);
    std::cout << s.id() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
