#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    bool prime = n >= 2;
    for (int d = 2; prime && d <= n / d; ++d) {
        if (n % d == 0)
            prime = false;
    }
    std::cout << (prime ? "YES" : "NO") << '\n';
    return 0;
}
