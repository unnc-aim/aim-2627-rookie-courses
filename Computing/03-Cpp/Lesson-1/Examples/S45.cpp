#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    for (char &c : s)
        if (c >= 'a' && c <= 'z')
            c = char(c - 'a' + 'A');
    std::cout << s << '\n';
    return 0;
}
