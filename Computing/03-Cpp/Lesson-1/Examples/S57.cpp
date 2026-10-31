#include <iostream>

void swap_value(int a, int b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    swap_value(a, b);
    std::cout << a << ' ' << b << '\n';
    return 0;
}
