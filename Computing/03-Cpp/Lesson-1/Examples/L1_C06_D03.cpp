#include <array>
#include <iostream>

int main() {
    std::array<int, 3> a = {1, 2, 3};
    for (int value : a) {
        value = 0;
    }
    for (int &value : a) {
        value *= 2;
    }
    for (int value : a) {
        std::cout << value << '\n';
    }
    return 0;
}
