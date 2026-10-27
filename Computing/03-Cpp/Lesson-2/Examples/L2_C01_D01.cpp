#include <iostream>

int test_add(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    int result = test_add(1, 2);
    std::cout << result << '\n';
    return 0;
}
