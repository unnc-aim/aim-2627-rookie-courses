#include <iostream>
#include <memory>

struct Base {
    virtual ~Base() { std::cout << "B\n"; }
};
struct Derived : Base {
    ~Derived() override { std::cout << "D\n"; }
};

int main() {
    std::unique_ptr<Base> p = std::make_unique<Derived>();
    return 0;
}
