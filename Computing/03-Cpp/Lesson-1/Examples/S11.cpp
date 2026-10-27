#include <iomanip>
#include <iostream>

int main() {
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    std::cout << std::fixed << std::setprecision(2) << (a + b + c) / 3.0 << '\n';
    return 0;
}
