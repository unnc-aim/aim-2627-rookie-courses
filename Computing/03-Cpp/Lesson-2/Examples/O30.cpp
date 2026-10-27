#include <iostream>
#include <string>

struct Base {
    std::string name() const { return "BASE"; }
};
struct Derived : Base {
    std::string name() const { return "DERIVED"; }
};

int main() {
    Derived d;
    std::cout << d.name() << ' ' << d.Base::name() << '\n';
    return 0;
}
