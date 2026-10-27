#include <iostream>

class Distance {
    int meters_;

  public:
    explicit Distance(int m) : meters_(m) {}
    int meters() const { return meters_; }
};
void print_distance(const Distance &d) { std::cout << d.meters() << '\n'; }

int main() {
    print_distance(Distance(3));
    return 0;
}
