#include <iomanip>
#include <iostream>

int main() {
    double c = 0.0;
    std::cin >> c;
    std::cout << std::fixed << std::setprecision(1) << c * 9.0 / 5.0 + 32.0 << '\n';
    return 0;
}
