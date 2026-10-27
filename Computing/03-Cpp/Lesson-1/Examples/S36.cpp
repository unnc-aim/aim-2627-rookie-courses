#include <array>
#include <iostream>

int main() {
    std::array<int, 3> a = {10, 20, 30};
    int index = 0;
    std::cin >> index;
    if (index < 0 || index >= static_cast<int>(a.size()))
        std::cout << "INVALID\n";
    else
        std::cout << a.at(index) << '\n';
    return 0;
}
