#include <iostream>

void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    swap1(x, y);
    std::cout << x << ' ' << y << '\n';
    return 0;
}
