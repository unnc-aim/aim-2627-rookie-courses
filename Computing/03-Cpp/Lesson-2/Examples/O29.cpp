#include <iostream>

struct Base {
    Base() { std::cout << "+B\n"; }
    ~Base() { std::cout << "-B\n"; }
};
struct Derived : Base {
    Derived() { std::cout << "+D\n"; }
    ~Derived() { std::cout << "-D\n"; }
};

int main() {
    Derived d;
    return 0;
}
