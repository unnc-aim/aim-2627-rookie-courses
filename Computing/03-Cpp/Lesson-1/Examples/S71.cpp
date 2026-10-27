#include <array>
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::array<bool, 101> seen = {};
    for (int i = 0; i < n; ++i) {
        int ts = 0, value = 0;
        std::cin >> ts >> value;
        if (!seen[ts]) {
            seen[ts] = true;
            std::cout << ts << ' ' << value << '\n';
        }
    }
    return 0;
}
