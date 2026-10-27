#include <iostream>
#include <vector>

int main() {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for (int &x : a)
        std::cin >> x;
    k %= n;
    for (int i = 0; i < n; ++i)
        b[(i + k) % n] = a[i];
    for (int x : b)
        std::cout << x << '\n';
    return 0;
}
