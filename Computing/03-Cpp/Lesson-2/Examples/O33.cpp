#include <iostream>
#include <string>

struct Base {
    virtual ~Base() = default;
    virtual std::string kind() const { return "BASE"; }
};
struct Derived : Base {
    std::string kind() const override { return "DERIVED"; }
};

int main() {
    Derived d;
    Base value = d;
    const Base &ref = d;
    std::cout << value.kind() << ' ' << ref.kind() << '\n';
    return 0;
}
