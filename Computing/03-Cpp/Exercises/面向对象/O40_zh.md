# O40 声明与类外定义

第 2 课 · 2.3 · 怎样使用和传递对象：const、this、复制与引用

## 题目

把 Motor 声明与成员定义分开，但仍保留在同一个 .cpp 中。set 限幅到 [-3,3]，设置 8 后输出 3。多文件拆分仅作为讲师本地工程扩展。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
3
```

## 逐步推导

类体只声明接口，类外用 Motor:: 给出实现，仍把所有部分放在同一平台源文件里。

## 关键规则与边界

类外定义使用 Motor::。CPP-Classroom 仍接收一份包含全部声明、定义和 main 的源文件。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>

class Motor {
    int speed_ = 0;

  public:
    void set(int v);
    int speed() const;
};
void Motor::set(int v) { speed_ = std::clamp(v, -3, 3); }
int Motor::speed() const { return speed_; }

int main() {
    Motor m;
    m.set(8);
    std::cout << m.speed() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
