#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> a;
    int value = 0;
    while (std::cin >> value)
        a.push_back(value);
    for (std::size_t i = a.size(); i > 0; --i)
        std::cout << a[i - 1] << '\n';
    return 0;
}
