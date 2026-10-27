#include <array>
#include <iostream>

int main() {
    std::array<int, 5> scores = {94, 87, 50};
    std::array<int, 5> replacement = {80, 85, 90, 95, 100};
    scores = replacement;
    std::cout << scores.size() << ' ' << scores.at(0) << '\n';
    return 0;
}
