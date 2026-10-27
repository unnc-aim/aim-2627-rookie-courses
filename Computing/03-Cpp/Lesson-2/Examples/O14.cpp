#include <iostream>
#include <vector>

class Buffer {
    std::vector<int> values_ = {1, 2};

  public:
    std::vector<int> copy() const { return values_; }
    const std::vector<int> &view() const { return values_; }
};

int main() {
    Buffer b;
    std::vector<int> c = b.copy();
    c[0] = 9;
    std::cout << b.view()[0] << ' ' << c[0] << '\n';
    return 0;
}
