#include <iostream>
#include <string>

int main() {
    int w = 0, h = 0, x = 0, y = 0, collisions = 0;
    std::string commands;
    std::cin >> w >> h >> commands;
    for (char c : commands) {
        int nx = x + (c == 'R') - (c == 'L');
        int ny = y + (c == 'U') - (c == 'D');
        if (nx < 0 || nx >= w || ny < 0 || ny >= h)
            ++collisions;
        else {
            x = nx;
            y = ny;
        }
    }
    std::cout << x << ' ' << y << ' ' << collisions << '\n';
    return 0;
}
