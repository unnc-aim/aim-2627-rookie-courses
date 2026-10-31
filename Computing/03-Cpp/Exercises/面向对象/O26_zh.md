# O26 public 继承

第 2 课 · 2.6 · 继承：派生对象中的基类部分

## 题目

Robot 提供 id=7，Sentry 公有继承 Robot 并增加 patrol，输出 id 和 PATROL。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
7
PATROL
```

## 逐步推导

先调用继承接口，再调用新增方法，区分接口来源。

## 关键规则与边界

public 继承表达 is-a 关系，派生对象能调用基类的 public 成员。

## 完整单文件参考程序

```cpp
#include <iostream>

class Robot {
  public:
    int id() const { return 7; }
};
class Sentry : public Robot {
  public:
    void patrol() const { std::cout << "PATROL\n"; }
};

int main() {
    Sentry s;
    std::cout << s.id() << '\n';
    s.patrol();
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
