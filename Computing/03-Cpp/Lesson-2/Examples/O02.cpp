#include <iostream>

class Counter {
    int count_ = 0;

  public:
    void tick() { ++count_; }
    int value() const { return count_; }
};

int main() {
    Counter a, b;
    a.tick();
    a.tick();
    std::cout << a.value() << ' ' << b.value() << '\n';
    return 0;
}
