#include <iomanip>
#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << a / b << ' ' << std::fixed << std::setprecision(2)
              << static_cast<double>(a) / b << '\n';
    return 0;
}
