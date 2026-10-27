#include <iostream>

class Limits {
  public:
    static bool valid(int speed) { return speed >= -3 && speed <= 3; }
};

int main() {
    std::cout << Limits::valid(3) << ' ' << Limits::valid(4) << '\n';
    return 0;
}
