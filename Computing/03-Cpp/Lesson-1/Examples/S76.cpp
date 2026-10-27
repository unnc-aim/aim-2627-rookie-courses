#include <algorithm>
#include <iostream>

int main() {
    int n = 0, h = 0, cool = 0, delta = 0, shots = 0;
    std::cin >> n >> h >> cool >> delta;
    for (int i = 0; i < n; ++i) {
        int fire = 0;
        std::cin >> fire;
        h = std::max(0, h - cool);
        if (fire && h + delta <= 100) {
            h += delta;
            ++shots;
        }
    }
    std::cout << shots << ' ' << h << '\n';
    return 0;
}
