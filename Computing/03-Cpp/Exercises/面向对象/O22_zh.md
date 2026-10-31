# O22 电池与动作组合

第 2 课 · 2.4 · 先学组合：一个对象拥有另一些对象

## 题目

Robot 持有电量 2 的 Battery，每次 step 消耗 1，仅足够时 x 加一，调用三次后输出 x 与剩余电量。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
2 0
```

## 逐步推导

前两步耗电并移动，第三步资源不足既不扣电也不移动。

## 关键规则与边界

耗电成功与位置变化组成同一动作，不应在失败路径部分修改状态。

## 完整单文件参考程序

```cpp
#include <iostream>

class Battery {
    int charge_ = 2;

  public:
    bool consume() {
        if (!charge_)
            return false;
        --charge_;
        return true;
    }
    int charge() const { return charge_; }
};
class Robot {
    Battery battery_;
    int x_ = 0;

  public:
    void step() {
        if (battery_.consume())
            ++x_;
    }
    void print() const { std::cout << x_ << ' ' << battery_.charge() << '\n'; }
};

int main() {
    Robot r;
    r.step();
    r.step();
    r.step();
    r.print();
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
