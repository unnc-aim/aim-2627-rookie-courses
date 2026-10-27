# O24 只读状态快照

Lesson 2 · Chapter 09 · 原课程整合与工程拓展

## 题目

Robot::snapshot 返回 State 值，拿到快照后修改其 x=99，原对象 x 仍为 3。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
3 99
```

## 逐步推导

返回副本后修改副本，再分别观察原对象和副本，确认存储独立。

## 关键规则与边界

返回值快照把外部观察和内部状态修改分开。

## 完整单文件参考程序

```cpp
#include <iostream>

struct State {
    int x = 0;
};
class Robot {
    State state_ = {3};

  public:
    State snapshot() const { return state_; }
};

int main() {
    Robot r;
    State state = r.snapshot();
    state.x = 99;
    std::cout << r.snapshot().x << ' ' << state.x << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
