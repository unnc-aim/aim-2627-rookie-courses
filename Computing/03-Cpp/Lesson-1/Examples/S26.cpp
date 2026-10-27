#include <iostream>

int main() {
    int x = 0;
    long long total = 0;
    while (std::cin >> x && x != -1)
        total += x;
    std::cout << total << '\n';
    return 0;
}
