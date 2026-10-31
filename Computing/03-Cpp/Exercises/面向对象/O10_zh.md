# O10 无默认构造的成员

第 2 课 · 2.2 · 构造对象时，就把它准备好

## 题目

Robot 持有 Motor，Motor 只接受 id 构造，Robot 必须初始化它；构造 Robot(4) 输出电机 id。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
4
```

## 逐步推导

Robot 的初始化列表直接构造 `motor_`，不先假设存在无参数 Motor。

## 关键规则与边界

先构造成员，再进入外层构造函数体。赋值无法替代缺失的成员构造。

## 完整单文件参考程序

```cpp
#include <iostream>

class Motor {
    int id_;

  public:
    explicit Motor(int id) : id_(id) {}
    int id() const { return id_; }
};
class Robot {
    Motor motor_;

  public:
    explicit Robot(int id) : motor_(id) {}
    int motor_id() const { return motor_.id(); }
};

int main() {
    Robot r(4);
    std::cout << r.motor_id() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
