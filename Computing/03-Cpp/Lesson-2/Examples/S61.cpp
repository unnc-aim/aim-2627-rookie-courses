#include <iostream>

int main() {
    int a = 3, b = 7;
    const int *p = &a;
    std::cout << *p << '\n';
    p = &b;
    std::cout << *p << '\n';
    return 0;
}
