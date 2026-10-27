#include <iostream>

int main() {
    int y = 0;
    std::cin >> y;
    bool leap = y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
    std::cout << (leap ? "LEAP" : "COMMON") << '\n';
    return 0;
}
