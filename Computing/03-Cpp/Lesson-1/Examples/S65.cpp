#include <iomanip>
#include <iostream>

struct Frame {
    int id = 0;
    int hp = 0;
    double speed = 0.0;
};

int main() {
    Frame frame = {};
    std::cin >> frame.id >> frame.hp >> frame.speed;
    std::cout << frame.id << ':' << frame.hp << ':' << std::fixed
              << std::setprecision(1) << frame.speed << '\n';
    return 0;
}
