#include <iostream>

void swap2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void swap_ref(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    swap2(&x, &y);
    std::cout << x << ' ' << y << '\n';
    swap_ref(x, y);
    std::cout << x << ' ' << y << '\n';
    return 0;
}
