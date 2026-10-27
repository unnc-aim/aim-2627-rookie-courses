#include <cmath>
#include <iostream>

int main() {
    double a = 0.0, b = 0.0;
    std::cin >> a >> b;
    std::cout << (std::abs(a - b) <= 1e-6 ? "SAME" : "DIFF") << '\n';
    return 0;
}
