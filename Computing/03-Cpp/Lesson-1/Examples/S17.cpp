#include <iostream>

int main() {
    int hp = 0;
    std::cin >> hp;
    if (hp == 0)
        std::cout << "DEAD\n";
    else if (hp <= 30)
        std::cout << "LOW\n";
    else
        std::cout << "OK\n";
    return 0;
}
