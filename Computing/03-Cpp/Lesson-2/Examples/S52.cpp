#include <iostream>

int scale(int value, int factor = 2) { return value * factor; }

int main() {
    int value = 0;
    std::cin >> value;
    std::cout << scale(value) << ' ' << scale(value, 3) << '\n';
    return 0;
}
