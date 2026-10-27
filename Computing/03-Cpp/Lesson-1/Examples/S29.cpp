#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0)
            std::cout << d << '\n';
    }
    return 0;
}
