#include <iostream>

int main() {
    int value = 0;
    if (!(std::cin >> value)) {
        std::cout << "INVALID\n";
    } else {
        std::cout << 2 * value << '\n';
    }
    return 0;
}
