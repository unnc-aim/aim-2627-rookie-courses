#include <iostream>

struct Motor {
    int speed = 0;
    void set(int v) { speed = v; }
};
class Chassis {
    Motor left_, right_;

  public:
    void drive(int l, int r) {
        left_.set(l);
        right_.set(r);
    }
    void print() const { std::cout << left_.speed << ' ' << right_.speed << '\n'; }
};

int main() {
    Chassis c;
    c.drive(2, 3);
    c.print();
    return 0;
}
