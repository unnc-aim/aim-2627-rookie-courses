#include <iostream>

int main() {
    int x = 0, y = 0;
    if (!(std::cin >> x >> y)) {
        std::cout << "INVALID\n";
        return 1;
    }
    std::cout << x + y << ' ' << x - y << '\n';
    return 0;
}
