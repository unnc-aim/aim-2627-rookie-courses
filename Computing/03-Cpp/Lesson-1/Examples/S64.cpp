#include <cstddef>
#include <iostream>

long long sum_span(const int *p, std::size_t n) {
    long long total = 0;
    for (std::size_t i = 0; i < n; ++i)
        total += p[i];
    return total;
}

int main() {
    int a[] = {2, 4, 6};
    std::cout << sum_span(a, 3) << ' ' << sum_span(nullptr, 0) << '\n';
    return 0;
}
