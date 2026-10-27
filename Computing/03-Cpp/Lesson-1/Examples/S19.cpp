#include <iostream>

int main() {
    int hp = 0, heat = 0, enemy = 0;
    std::cin >> hp >> heat >> enemy;
    bool fire = hp > 0 && heat < 100 && enemy == 1;
    std::cout << (fire ? "FIRE" : "WAIT") << '\n';
    return 0;
}
