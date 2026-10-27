#include <iostream>

enum class Facing { Up, Right, Down, Left };

int main() {
    int raw = 0;
    std::cin >> raw;
    Facing facing = static_cast<Facing>(raw);
    facing = static_cast<Facing>((static_cast<int>(facing) + 1) % 4);
    std::cout << static_cast<int>(facing) << '\n';
    return 0;
}
