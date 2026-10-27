#include <array>
#include <iostream>

int main() {
    std::array<int, 5> scores = {94, 87, 50};
    for (int score : scores)
        std::cout << score << '\n';
    return 0;
}
