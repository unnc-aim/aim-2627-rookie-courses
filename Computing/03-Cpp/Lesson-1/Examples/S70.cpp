#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    int n = 0, k = 0;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (i >= k)
            sum -= a[i - k];
        if (i >= k - 1)
            std::cout << std::fixed << std::setprecision(2)
                      << static_cast<double>(sum) / k << '\n';
    }
    return 0;
}
