#include <iostream>
#include <string>

struct Robot {
    virtual ~Robot() = default;
    virtual std::string kind() const { return "ROBOT"; }
};
struct Sentry : Robot {
    std::string kind() const override { return "SENTRY"; }
};

int main() {
    Sentry object;
    const Robot &ref = object;
    Robot sliced = object;
    std::cout << ref.kind() << ' ' << sliced.kind() << '\n';
    return 0;
}
