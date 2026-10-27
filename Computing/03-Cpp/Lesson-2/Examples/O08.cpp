#include <algorithm>
#include <iostream>

class Timer {
    int interval_;

  public:
    Timer() : Timer(100) {}
    explicit Timer(int ms) : interval_(std::max(1, ms)) {}
    int interval() const { return interval_; }
};

int main() {
    Timer a;
    Timer b(0);
    std::cout << a.interval() << ' ' << b.interval() << '\n';
    return 0;
}
