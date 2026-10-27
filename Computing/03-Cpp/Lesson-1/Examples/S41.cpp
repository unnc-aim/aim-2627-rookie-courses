#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << s.size() << '\n';
    if (!s.empty())
        std::cout << s.front() << ' ' << s.back() << '\n';
    return 0;
}
