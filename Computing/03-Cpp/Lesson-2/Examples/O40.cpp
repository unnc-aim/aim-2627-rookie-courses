#include <algorithm>
#include <iostream>

class Motor {
    int speed_ = 0;

  public:
    void set(int v);
    int speed() const;
};
void Motor::set(int v) { speed_ = std::clamp(v, -3, 3); }
int Motor::speed() const { return speed_; }

int main() {
    Motor m;
    m.set(8);
    std::cout << m.speed() << '\n';
    return 0;
}
