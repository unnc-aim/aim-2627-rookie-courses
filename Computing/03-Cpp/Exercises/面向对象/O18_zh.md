# O18 作用域销毁顺序

Lesson 2 · Chapter 06 · 实例、方法与乐队集合

## 题目

Tracer 构造输出 +名称，析构输出 -名称。外层 a，内层 b，随后结束 main，预测全部输出。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
+a
+b
-b
-a
```

## 逐步推导

b 先离开内层块，a 到 main 结束才销毁，按时间线排列四行输出。

## 关键规则与边界

自动存储期对象在离开作用域时析构，同一作用域按完成构造的逆序销毁。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <string>
#include <utility>

class Tracer {
    std::string name_;

  public:
    explicit Tracer(std::string name) : name_(std::move(name)) {
        std::cout << '+' << name_ << '\n';
    }
    ~Tracer() { std::cout << '-' << name_ << '\n'; }
};

int main() {
    Tracer a("a");
    {
        Tracer b("b");
    }
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
