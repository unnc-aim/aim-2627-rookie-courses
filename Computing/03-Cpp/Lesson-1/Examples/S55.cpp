#include <iostream>

unsigned long long factorial(int n) {
    return n <= 1 ? 1ULL : static_cast<unsigned long long>(n) * factorial(n - 1);
}

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << factorial(n) << '\n';
    return 0;
}
