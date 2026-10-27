#include <iostream>
#include <string>

int main() {
    std::string band1 = "poppin party";
    std::string band2 = "mygo";
    std::string *anime1 = &band1;
    *anime1 = "afterglow";
    anime1 = &band2;
    std::cout << band1 << ' ' << *anime1 << '\n';
    return 0;
}
