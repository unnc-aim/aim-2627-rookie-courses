#include <iostream>
#include <memory>
#include <utility>

int main() {
    std::unique_ptr<int> first = std::make_unique<int>(7);
    std::unique_ptr<int> second = std::move(first);
    std::cout << std::boolalpha << (first == nullptr) << ' ' << *second << '\n';
    return 0;
}
