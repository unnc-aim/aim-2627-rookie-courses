#include <iomanip>
#include <iostream>

int main() {
    std::cout << 3 % 2 << ' ' << 3 / 2 << '\n';
    std::cout << std::fixed << std::setprecision(2) << static_cast<double>(3) / 2
              << ' ' << static_cast<double>(3 / 2) << '\n';
    return 0;
}
