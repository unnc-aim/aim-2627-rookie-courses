#include <iostream>

class Config {
    int speed_ = 0, id_ = 0;

  public:
    Config &set_speed(int v) {
        speed_ = v;
        return *this;
    }
    Config &set_id(int id) {
        id_ = id;
        return *this;
    }
    void print() const { std::cout << id_ << ':' << speed_ << '\n'; }
};

int main() {
    Config c;
    c.set_speed(3).set_id(7).print();
    return 0;
}
