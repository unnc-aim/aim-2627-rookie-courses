#include <iostream>

class Battery {
    int charge_ = 2;

  public:
    bool consume() {
        if (!charge_)
            return false;
        --charge_;
        return true;
    }
    int charge() const { return charge_; }
};
class Robot {
    Battery battery_;
    int x_ = 0;

  public:
    void step() {
        if (battery_.consume())
            ++x_;
    }
    void print() const { std::cout << x_ << ' ' << battery_.charge() << '\n'; }
};

int main() {
    Robot r;
    r.step();
    r.step();
    r.step();
    r.print();
    return 0;
}
