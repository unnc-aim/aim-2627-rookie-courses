#include <iostream>
#include <string>

int main() {
    std::string band = "mygo";
    const std::string *p = nullptr;
    if (p != nullptr) {
        std::cout << *p << '\n';
    }
    p = &band;
    std::cout << *p << '\n';
    return 0;
}
