#include <iostream>

void swap_ref(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    swap_ref(a, b);
    std::cout << a << ' ' << b << '\n';
    return 0;
}
