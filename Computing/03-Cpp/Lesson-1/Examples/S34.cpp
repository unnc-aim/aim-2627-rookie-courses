#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    int best = a[0];
    for (int x : a)
        best = std::max(best, x);
    std::cout << best << '\n';
    return 0;
}
