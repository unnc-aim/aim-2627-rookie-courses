#include <algorithm>
#include <iostream>
#include <vector>

struct Unit {
    int id = 0;
    int hp = 0;
};

int main() {
    int n = 0, alive = 0;
    std::cin >> n;
    std::vector<Unit> units(n);
    for (Unit & u : units) {
        std::cin >> u.id >> u.hp;
        u.hp = std::clamp(u.hp, 0, 100);
        alive += u.hp > 0;
    }
    std::sort(units.begin(), units.end(),
              [](const Unit &a, const Unit &b) { return a.id < b.id; });
    for (const Unit & u : units)
        std::cout << u.id << ':' << u.hp << '\n';
    std::cout << "ALIVE=" << alive << '\n';
    return 0;
}
