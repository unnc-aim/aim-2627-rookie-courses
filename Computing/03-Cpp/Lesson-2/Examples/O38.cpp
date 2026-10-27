#include <iostream>
#include <stdexcept>

struct Guard {
    Guard() { std::cout << "ACQUIRE\n"; }
    ~Guard() { std::cout << "RELEASE\n"; }
};

int main() {
    try {
        Guard guard;
        throw std::runtime_error("demo");
    } catch (const std::runtime_error &) {
        std::cout << "CAUGHT\n";
    }
    return 0;
}
