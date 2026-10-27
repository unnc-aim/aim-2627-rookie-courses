#include <iostream>

int main() {
    double speed = 0.0;
    std::cin >> speed;
    std::cout << (speed >= -3 && speed <= 3 ? "SAFE" : "UNSAFE") << '\n';
    return 0;
}
