#include <iostream>
#include <string>
#include <utility>

class BandInit {
    std::string guitar;
    std::string keyboard;

  public:
    BandInit(std::string gt, std::string key)
        : guitar(std::move(gt)), keyboard(std::move(key)) {}
    void print() const { std::cout << guitar << ':' << keyboard << '\n'; }
};

int main() {
    BandInit band("mutsumi", "saki");
    band.print();
    return 0;
}
