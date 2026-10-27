#include <iostream>

int main() {
    int r = 0, c = 0;
    std::cin >> r >> c;
    for (int y = 0; y < r; ++y) {
        for (int x = 0; x < c; ++x)
            std::cout << '#';
        std::cout << '\n';
    }
    return 0;
}
