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
