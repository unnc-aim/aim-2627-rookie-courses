#include <iostream>

struct Sensor {
    virtual ~Sensor() = default;
    virtual int read() const = 0;
};
struct FixedSensor : Sensor {
    int read() const override { return 42; }
};
void print_sensor(const Sensor &s) { std::cout << s.read() << '\n'; }

int main() {
    FixedSensor s;
    print_sensor(s);
    return 0;
}
