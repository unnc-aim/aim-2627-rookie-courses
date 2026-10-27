#include <iostream>

int main() {
    char op = '\0';
    std::cin >> op;
    switch (op) {
    case 'F':
        std::cout << "FORWARD\n";
        break;
    case 'L':
        std::cout << "LEFT\n";
        break;
    case 'R':
        std::cout << "RIGHT\n";
        break;
    default:
        std::cout << "UNKNOWN\n";
    }
    return 0;
}
