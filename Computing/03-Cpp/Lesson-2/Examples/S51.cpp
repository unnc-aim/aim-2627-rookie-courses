#include <algorithm>
#include <iostream>

int clamp_speed(int v, int limit) { return std::max(-limit, std::min(v, limit)); }

int main() {
    int v = 0, limit = 0;
    std::cin >> v >> limit;
    std::cout << clamp_speed(v, limit) << '\n';
    return 0;
}
