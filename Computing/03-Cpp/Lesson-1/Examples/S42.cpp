#include <iostream>
#include <string>

int main() {
    std::string text, key;
    std::getline(std::cin, text);
    std::getline(std::cin, key);
    std::string::size_type pos = text.find(key);
    if (pos == std::string::npos)
        std::cout << -1 << '\n';
    else
        std::cout << pos << '\n';
    return 0;
}
