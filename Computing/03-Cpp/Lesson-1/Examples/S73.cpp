#include <iostream>

int main() {
    int n = 0, valid = 0, sum = 0, x = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (0 <= x && x <= 100) {
            ++valid;
            sum += x;
        }
    }
    std::cout << valid << ' ' << sum << '\n';
    return 0;
}
