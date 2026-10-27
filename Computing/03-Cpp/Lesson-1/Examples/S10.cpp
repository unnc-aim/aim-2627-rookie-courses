#include <iostream>

int main() {
    int seconds = 0;
    std::cin >> seconds;
    std::cout << seconds / 3600 << ' ' << seconds / 60 % 60 << ' ' << seconds % 60
              << '\n';
    return 0;
}
