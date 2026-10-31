#include <iostream>

void safe_increment(int *p) {
    if (p != nullptr)
        ++*p;
}

int main() {
    int x = 7;
    safe_increment(nullptr);
    safe_increment(&x);
    std::cout << x << '\n';
    return 0;
}
