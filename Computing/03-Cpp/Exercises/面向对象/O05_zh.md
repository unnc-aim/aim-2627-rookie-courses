# O05 struct 与 class

第 2 课 · 2.1 · 从一份记录到一个会做事的对象

## 题目

定义 struct Point 和 class Hidden，各自含 int x，Point 直接访问，Hidden 通过 getter 访问，都输出 3。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
3 3
```

## 逐步推导

显式保留两个类型的默认访问差异，不把 class 的私有字段公开来绕过接口。

## 关键规则与边界

struct/class 的主要语言差别是默认成员访问与默认继承访问权限。

## 完整单文件参考程序

```cpp
#include <iostream>

struct Point {
    int x = 3;
};
class Hidden {
    int x = 3;

  public:
    int value() const { return x; }
};

int main() {
    Point p;
    Hidden h;
    std::cout << p.x << ' ' << h.value() << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
