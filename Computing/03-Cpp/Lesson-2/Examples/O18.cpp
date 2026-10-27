#include <iostream>
#include <string>
#include <utility>

class Tracer {
    std::string name_;

  public:
    explicit Tracer(std::string name) : name_(std::move(name)) {
        std::cout << '+' << name_ << '\n';
    }
    ~Tracer() { std::cout << '-' << name_ << '\n'; }
};

int main() {
    Tracer a("a");
    {
        Tracer b("b");
    }
    return 0;
}
