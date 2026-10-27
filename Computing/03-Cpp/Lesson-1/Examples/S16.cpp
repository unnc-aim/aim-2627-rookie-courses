#include <iostream>

int main() {
    long long n = 0, k = 0;
    std::cin >> n >> k;
    std::cout << n / k + (n % k != 0) << '\n';
    return 0;
}
