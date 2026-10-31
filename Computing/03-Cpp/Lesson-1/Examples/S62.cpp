#include <iostream>
#include <vector>

long long sum(const std::vector<int> &a) {
    long long result = 0;
    for (int x : a)
        result += x;
    return result;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a)
        std::cin >> x;
    std::cout << sum(a) << '\n';
    return 0;
}
