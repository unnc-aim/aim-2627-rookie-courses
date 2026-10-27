#include <iostream>
#include <vector>

std::vector<int> make_values() { return {1, 2, 3}; }

int main() {
    std::vector<int> values = make_values();
    std::cout << values.size() << ' ' << values.front() << '\n';
    return 0;
}
