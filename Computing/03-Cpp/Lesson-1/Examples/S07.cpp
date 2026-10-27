#include <iostream>

namespace aim {
int speed = 3;
}
namespace sim {
int speed = 8;
}

int main() {
    std::cout << aim::speed << ' ' << sim::speed << '\n';
    return 0;
}
