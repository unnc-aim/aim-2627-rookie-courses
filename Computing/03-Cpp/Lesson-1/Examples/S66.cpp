#include <iostream>
#include <limits>

struct Target {
    int id = 0;
    int x = 0;
    int y = 0;
};

int main() {
    int n = 0;
    std::cin >> n;
    Target best = {};
    long long best_d = std::numeric_limits<long long>::max();
    for (int i = 0; i < n; ++i) {
        Target t = {};
        std::cin >> t.id >> t.x >> t.y;
        long long d = 1LL * t.x * t.x + 1LL * t.y * t.y;
        if (d < best_d || (d == best_d && t.id < best.id)) {
            best = t;
            best_d = d;
        }
    }
    std::cout << best.id << '\n';
    return 0;
}
