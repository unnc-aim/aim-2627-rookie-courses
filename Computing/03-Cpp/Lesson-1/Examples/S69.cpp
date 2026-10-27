#include <iostream>
#include <string>

int main() {
    std::string commands;
    std::cin >> commands;
    int x = 0, y = 0;
    for (char c : commands) {
        if (c == 'U')
            ++y;
        else if (c == 'D')
            --y;
        else if (c == 'L')
            --x;
        else if (c == 'R')
            ++x;
    }
    std::cout << x << ' ' << y << '\n';
    return 0;
}
