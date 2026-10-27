#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    for (int i = 1; i < n; ++i)
        std::cout << a[i] - a[i - 1] << '\n';
    return 0;
}
