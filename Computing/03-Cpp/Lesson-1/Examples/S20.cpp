#include <iostream>

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    if (b == 0)
        std::cout << "INVALID\n";
    else
        std::cout << std::boolalpha << (a / b > 2) << '\n';
    return 0;
}
