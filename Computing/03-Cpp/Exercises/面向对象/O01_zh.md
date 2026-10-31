# O01 第一个类

第 2 课 · 2.1 · 从一份记录到一个会做事的对象

## 题目

定义 Robot 含公开 id 与 greet()，创建 id=7 对象并调用 greet 输出 Robot 7。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
Robot 7
```

## 逐步推导

先定义类型，再建立对象并设定 id，方法通过当前对象读取该字段。

## 关键规则与边界

类定义描述类型，创建对象才得到具体实例。

## 完整单文件参考程序

```cpp
#include <iostream>

class Robot {
  public:
    int id = 0;
    void greet() const { std::cout << "Robot " << id << '\n'; }
};

int main() {
    Robot robot;
    robot.id = 7;
    robot.greet();
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
