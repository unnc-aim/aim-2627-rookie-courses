#include <iostream>

int square(int x);
int square(int x) { return x * x; }

int main() {
    int x = 0;
    std::cin >> x;
    std::cout << square(x) << '\n';
    return 0;
}
