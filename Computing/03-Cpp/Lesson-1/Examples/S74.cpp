#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (std::size_t i = 0; i < s.size();) {
        std::size_t j = i + 1;
        while (j < s.size() && s[j] == s[i])
            ++j;
        std::cout << s[i] << ':' << j - i << '\n';
        i = j;
    }
    return 0;
}
