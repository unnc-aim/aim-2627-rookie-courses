#include <iostream>

int main() {
    int n = 0, sum = 0;
    std::cin >> n;
    do {
        sum += n % 10;
        n /= 10;
    } while (n != 0);
    std::cout << sum << '\n';
    return 0;
}
