#include <iostream>
#include <string>

int main() {
    std::string band1 = "poppin party";
    std::string &live1 = band1;
    live1 = "afterglow";
    std::cout << band1 << '\n';
    std::cout << std::boolalpha << (&band1 == &live1) << '\n';
    return 0;
}
