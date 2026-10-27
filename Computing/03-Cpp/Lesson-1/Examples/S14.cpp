#include <cmath>
#include <iomanip>
#include <iostream>

int main() {
    double x = 0.0, y = 0.0;
    std::cin >> x >> y;
    std::cout << std::fixed << std::setprecision(2) << std::hypot(x, y) << '\n';
    return 0;
}
