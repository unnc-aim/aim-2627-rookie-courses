#include <iostream>

int test_add(int a, int b) { return a + b; }
void print_sum(int a, int b) { std::cout << test_add(a, b) << '\n'; }

int main() {
    print_sum(4, 5);
    return 0;
}
