# O09 explicit 防止隐式转换

Lesson 2 · Chapter 05 · Band 的构造与初始化

## 题目

Distance 由米数构造，显式创建 Distance(3)，print_distance 接受 const Distance& 并输出值。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
3
```

## 逐步推导

对比显式构造与省略构造的调用，正常程序只保留合法版本。

## 关键规则与边界

print_distance(3) 在 explicit 下不能编译，必须明确构造对象。

## 完整单文件参考程序

```cpp
#include <iostream>

class Distance {
    int meters_;

  public:
    explicit Distance(int m) : meters_(m) {}
    int meters() const { return meters_; }
};
void print_distance(const Distance &d) { std::cout << d.meters() << '\n'; }

int main() {
    print_distance(Distance(3));
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
