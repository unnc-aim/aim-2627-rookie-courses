#include <algorithm>
#include <iostream>

int main() {
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    int lo = std::min(a, std::min(b, c));
    int hi = std::max(a, std::max(b, c));
    std::cout << a + b + c - lo - hi << '\n';
    return 0;
}
