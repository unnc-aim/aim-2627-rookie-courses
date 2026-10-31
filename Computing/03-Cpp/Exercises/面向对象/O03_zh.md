# O03 private 访问边界

第 2 课 · 2.1 · 从一份记录到一个会做事的对象

## 题目

Motor 的 `speed_` 私有，set_speed 把请求夹到 [-3,3]，getter 返回速度。分别请求 9、-9 并输出。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
3
-3
```

## 逐步推导

调用者只提供请求，限幅在类内部完成，随后通过 getter 验证两端。

## 关键规则与边界

封装让状态修改经过统一的约束入口。

## 完整单文件参考程序

```cpp
#include <algorithm>
#include <iostream>

class Motor {
    int speed_ = 0;

  public:
    void set_speed(int v) { speed_ = std::clamp(v, -3, 3); }
    int speed() const { return speed_; }
};

int main() {
    Motor m;
    m.set_speed(9);
    std::cout << m.speed() << '\n';
    m.set_speed(-9);
    std::cout << m.speed() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
