#include <algorithm>
#include <iostream>

class Battery {
    int capacity_;
    int charge_;

  public:
    Battery(int capacity, int initial)
        : capacity_(std::max(1, capacity)),
          charge_(std::clamp(initial, 0, capacity_)) {}
    int charge() const { return charge_; }
};

int main() {
    Battery b(10, 20);
    std::cout << b.charge() << '\n';
    return 0;
}
