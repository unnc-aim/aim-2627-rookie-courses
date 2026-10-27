#include <algorithm>
#include <iostream>

int main() {
    int n = 0, value = 0, run = 0, best = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        run = value == 1 ? run + 1 : 0;
        best = std::max(best, run);
    }
    std::cout << best << '\n';
    return 0;
}
