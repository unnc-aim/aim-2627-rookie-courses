#include <iostream>

int main() {
    int x = 0;
    long long total = 0;
    while (std::cin >> x) {
        if (x == 0)
            break;
        if (x < 0)
            continue;
        total += x;
    }
    std::cout << total << '\n';
    return 0;
}
