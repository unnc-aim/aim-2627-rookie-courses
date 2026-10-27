#include <iostream>

struct State {
    int x = 0;
};
class Robot {
    State state_ = {3};

  public:
    State snapshot() const { return state_; }
};

int main() {
    Robot r;
    State state = r.snapshot();
    state.x = 99;
    std::cout << r.snapshot().x << ' ' << state.x << '\n';
    return 0;
}
