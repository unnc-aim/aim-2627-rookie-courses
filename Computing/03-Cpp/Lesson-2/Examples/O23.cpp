#include <algorithm>
#include <iostream>

struct Policy {
    int max_speed = 1;
};
class Controller {
    Policy policy_;

  public:
    explicit Controller(Policy p) : policy_(p) {}
    int command(int v) const {
        return std::clamp(v, -policy_.max_speed, policy_.max_speed);
    }
};

int main() {
    Controller a(Policy{2}), b(Policy{5});
    std::cout << a.command(4) << ' ' << b.command(4) << '\n';
    return 0;
}
