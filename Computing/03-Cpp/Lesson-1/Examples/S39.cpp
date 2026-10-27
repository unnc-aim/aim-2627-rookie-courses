#include <iostream>
#include <vector>

int main() {
    int n = 0, x = 0;
    std::cin >> n;
    std::vector<int> valid;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (x >= 0)
            valid.push_back(x);
    }
    for (int v : valid)
        std::cout << v << '\n';
    return 0;
}
