#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    long long prev = 0;
    for (int i = 0; i < n; ++i) {
        long long ts = 0;
        std::cin >> ts;
        if (i > 0 && ts - prev > 10)
            std::cout << ts << '\n';
        prev = ts;
    }
    return 0;
}
