#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int value = 0;
        std::cin >> value;
        sum += value;
    }
    std::cout << sum << '\n';
    return 0;
}
