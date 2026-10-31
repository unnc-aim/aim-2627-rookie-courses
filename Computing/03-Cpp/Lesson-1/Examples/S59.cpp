#include <iostream>

int main() {
    int x = 5;
    int *p = &x;
    *p = 9;
    std::cout << x << ' ' << std::boolalpha << (p == &x) << '\n';
    return 0;
}
