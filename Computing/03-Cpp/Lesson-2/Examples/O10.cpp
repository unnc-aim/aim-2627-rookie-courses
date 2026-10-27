#include <iostream>

class Motor {
    int id_;

  public:
    explicit Motor(int id) : id_(id) {}
    int id() const { return id_; }
};
class Robot {
    Motor motor_;

  public:
    explicit Robot(int id) : motor_(id) {}
    int motor_id() const { return motor_.id(); }
};

int main() {
    Robot r(4);
    std::cout << r.motor_id() << '\n';
    return 0;
}
