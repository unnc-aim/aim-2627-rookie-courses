# O32 纯虚接口

第 2 课 · 2.7 · 多态：用同一个接口操作不同对象

## 题目

定义抽象 Sensor::read() const，FixedSensor 返回 42，print_sensor 接受 const Sensor& 并输出 read。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
42
```

## 逐步推导

只实例化具体派生类，统一函数通过抽象接口观察结果。

## 关键规则与边界

含未实现纯虚函数的类是抽象类，不能直接实例化。

## 完整单文件参考程序

```cpp
#include <iostream>

struct Sensor {
    virtual ~Sensor() = default;
    virtual int read() const = 0;
};
struct FixedSensor : Sensor {
    int read() const override { return 42; }
};
void print_sensor(const Sensor &s) { std::cout << s.read() << '\n'; }

int main() {
    FixedSensor s;
    print_sensor(s);
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
