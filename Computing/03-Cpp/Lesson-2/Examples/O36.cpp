#include <iostream>
#include <memory>
#include <utility>

// std::unique_ptr and std::move come from the standard library.

int main() {
    std::unique_ptr<int> a = std::make_unique<int>(7);
    std::unique_ptr<int> b = std::move(a);
    std::cout << std::boolalpha << (a == nullptr) << ' ' << *b << '\n';
    return 0;
}
