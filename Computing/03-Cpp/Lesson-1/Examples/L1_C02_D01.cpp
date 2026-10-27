#include <iostream>

namespace aim {
int cout = 310;
}

int main() {
    std::cout << aim::cout << '\n';
    ::std::cout << "standard output\n";
    return 0;
}
