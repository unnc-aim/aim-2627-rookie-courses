#include <iostream>
#include <vector>

struct Robot {
    std::vector<int> values = {1, 2};
};

int main() {
    Robot a;
    Robot b = a;
    b.values[0] = 9;
    std::cout << a.values[0] << ' ' << b.values[0] << '\n';
    return 0;
}
