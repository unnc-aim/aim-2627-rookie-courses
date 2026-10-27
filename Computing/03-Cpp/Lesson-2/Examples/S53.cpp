#include <iostream>
#include <string>

std::string label(int) { return "INT"; }
std::string label(double) { return "DOUBLE"; }

int main() {
    std::cout << label(3) << ' ' << label(3.0) << '\n';
    return 0;
}
