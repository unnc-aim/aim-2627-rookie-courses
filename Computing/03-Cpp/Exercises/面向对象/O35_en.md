# O35 A polymorphic collection

Lesson 2 · Section 2.8

## Problem

Shape has pure virtual area. Store a side-3 Square and a 2x4 Rectangle in `vector<unique_ptr<Shape>>`, then print total area.

## Sample input

```text
(no input)
```

## Sample output

```text
17
```

## Step-by-step reasoning

Store owning pointers, dispatch area for each object, and sum nine and eight.

## Rules and boundaries

Owning pointers preserve heterogeneous derived objects and avoid value slicing.

## Complete single-file reference program

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

## Verify in CPP-Classroom

Paste the entire program into the current exercise. Prefill the sample input and compare every stdout line. Run no-input demonstrations directly. In interactive mode, send EOF when a read-until-end example is complete.
