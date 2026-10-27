#include <iostream>

class Counter {
    int value_;

  public:
    explicit Counter(int n) : value_(n) {}
    int value() const { return value_; }
    void tick() { ++value_; }
};

int main() {
    const Counter c(8);
    std::cout << c.value() << '\n';
    return 0;
}
