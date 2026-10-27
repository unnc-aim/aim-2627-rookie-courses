#include <iostream>
#include <vector>

class Unit {
    int id_;

  public:
    explicit Unit(int id) : id_(id) {}
    int id() const { return id_; }
};

int main() {
    std::vector<Unit> units;
    units.emplace_back(2);
    units.emplace_back(7);
    for (const Unit & u : units)
        std::cout << u.id() << '\n';
    return 0;
}
