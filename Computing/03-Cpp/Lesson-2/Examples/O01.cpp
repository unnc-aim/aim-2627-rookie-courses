#include <iostream>

class Robot {
  public:
    int id = 0;
    void greet() const { std::cout << "Robot " << id << '\n'; }
};

int main() {
    Robot robot;
    robot.id = 7;
    robot.greet();
    return 0;
}
