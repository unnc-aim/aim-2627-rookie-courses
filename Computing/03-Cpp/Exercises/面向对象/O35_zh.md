# O35 多态容器

第 2 课 · 2.8 · 动态对象、独占所有权与异常清理

## 题目

Shape::area 纯虚函数，Square 边长 3，Rectangle 边长 2、4。用 `vector<unique_ptr<Shape>>` 保存并输出总面积。

## 样例输入

```text
（无输入）
```

## 样例输出

```text
17
```

## 逐步推导

容器保存拥有指针，逐个虚调用 area，累加 9 与 8。

## 关键规则与边界

用拥有指针保存不同派生类型，避免 `vector<Shape>` 的切片问题。

## 完整单文件参考程序

```cpp
#include <iostream>
#include <memory>
#include <vector>

struct Shape {
    virtual ~Shape() = default;
    virtual int area() const = 0;
};
struct Square : Shape {
    int side;
    explicit Square(int s) : side(s) {}
    int area() const override { return side * side; }
};
struct Rectangle : Shape {
    int w, h;
    Rectangle(int a, int b) : w(a), h(b) {}
    int area() const override { return w * h; }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Square>(3));
    shapes.push_back(std::make_unique<Rectangle>(2, 4));
    int total = 0;
    for (const std::unique_ptr<Shape> & s : shapes)
        total += s->area();
    std::cout << total << '\n';
    return 0;
}
```

## 在 CPP-Classroom 中验证

整份复制上面的程序到当前练习。预填样例输入并运行，对照 stdout 的每一行；没有输入的示例直接运行。读取直到 EOF 的示例，在交互模式结束时发送 EOF。
