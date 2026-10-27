#include <algorithm>
#include <iostream>

class Motor {
    int speed_ = 0;

  public:
    void set_speed(int v) { speed_ = std::clamp(v, -3, 3); }
    int speed() const { return speed_; }
};

int main() {
    Motor m;
    m.set_speed(9);
    std::cout << m.speed() << '\n';
    m.set_speed(-9);
    std::cout << m.speed() << '\n';
    return 0;
}
