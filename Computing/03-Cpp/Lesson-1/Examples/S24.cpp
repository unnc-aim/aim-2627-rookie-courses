#include <iostream>

int main() {
    int stop = 0, hp = 0, enemy = 0;
    std::cin >> stop >> hp >> enemy;
    if (stop)
        std::cout << "STOP\n";
    else if (hp <= 0)
        std::cout << "DEAD\n";
    else if (enemy)
        std::cout << "TRACK\n";
    else
        std::cout << "PATROL\n";
    return 0;
}
