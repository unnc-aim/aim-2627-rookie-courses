#include <iostream>
#include <string>

struct Frame {
    int id = 0;
    int hp = 0;
    std::string name;
};

int main() {
    Frame a = {7, 80, "Sentry"};
    Frame b = a;
    a.hp = 30;
    std::cout << a.id << ':' << a.hp << '\n';
    std::cout << b.id << ':' << b.hp << '\n';
    return 0;
}
