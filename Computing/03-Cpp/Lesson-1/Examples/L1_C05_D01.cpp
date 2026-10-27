#include <iostream>

int main() {
    int x = 0;
    std::cin >> x;
    if (x > 0) {
        std::cout << "POSITIVE\n";
    } else if (x < 0) {
        std::cout << "NEGATIVE\n";
    } else {
        std::cout << "ZERO\n";
    }
    return 0;
}
