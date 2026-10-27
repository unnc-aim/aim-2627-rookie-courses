#include <iostream>

class Sensor {
    const int id_;

  public:
    explicit Sensor(int id) : id_(id) {}
    int id() const { return id_; }
};

int main() {
    Sensor s(7);
    std::cout << s.id() << '\n';
    return 0;
}
