#include <iostream>

int main() {
    int value = 3;
    {
        int doubled = value * 2;
        std::cout << doubled << '\n';
    }
    std::cout << value << '\n';
    return 0;
}
