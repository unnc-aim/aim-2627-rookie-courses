#include <array>
#include <iostream>

int main() {
    std::array<std::array<int, 3>, 2> grid = {};
    for (std::array<int, 3> & row : grid)
        for (int &x : row)
            std::cin >> x;
    for (const std::array<int, 3> & row : grid) {
        int sum = 0;
        for (int x : row)
            sum += x;
        std::cout << sum << '\n';
    }
    return 0;
}
