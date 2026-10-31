#include <iostream>

int main() {
    int x = 1;
    {
        int x = 2;
        std::cout << x << '\n';
    }
    std::cout << x << '\n';
    return 0;
}
