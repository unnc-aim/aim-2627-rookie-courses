#include <iostream>
#include <vector>

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = a;
    b[0] = 9;
    std::cout << a[0] << ' ' << b[0] << '\n';
    return 0;
}
