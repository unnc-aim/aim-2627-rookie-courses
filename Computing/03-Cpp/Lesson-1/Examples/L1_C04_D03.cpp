#include <iostream>

int main() {
    int a = 9, b = 0;
    bool valid = b != 0 && a / b > 2;
    std::cout << std::boolalpha << valid << '\n';
    std::cout << !(3 > 1 && 3 < 5) << '\n';
    return 0;
}
