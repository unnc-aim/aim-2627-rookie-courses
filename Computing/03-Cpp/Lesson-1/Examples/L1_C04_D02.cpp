#include <iostream>

int main() {
    int x = 10, y = 1;
    std::cout << std::boolalpha << (x == y) << '\n';
    y = x;
    std::cout << (x == y) << ' ' << (y != x) << '\n';
    return 0;
}
