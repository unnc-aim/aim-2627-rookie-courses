#include <iostream>

class Device {
  public:
    Device() = default;
    Device(const Device &) = delete;
    Device &operator=(const Device &) = delete;
    int id() const { return 7; }
};

int main() {
    Device d;
    std::cout << d.id() << '\n';
    return 0;
}
