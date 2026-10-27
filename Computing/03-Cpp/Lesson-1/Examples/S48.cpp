#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    bool yes = true;
    for (std::size_t i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - 1 - i])
            yes = false;
    std::cout << (yes ? "YES" : "NO") << '\n';
    return 0;
}
