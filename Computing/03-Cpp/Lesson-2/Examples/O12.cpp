#include <iostream>

class Pose {
    int x = 0;

  public:
    void set_x(int x) { this->x = x; }
    int get_x() const { return x; }
};

int main() {
    Pose p;
    p.set_x(5);
    std::cout << p.get_x() << '\n';
    return 0;
}
