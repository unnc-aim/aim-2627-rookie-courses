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
