#include <iostream>

bool safe_divide(int a, int b, int &out) {
    if (b == 0)
        return false;
    out = a / b;
    return true;
}

int main() {
    int a = 0, b = 0, answer = 99;
    std::cin >> a >> b;
    bool ok = safe_divide(a, b, answer);
    std::cout << std::boolalpha << ok << ' ' << answer << '\n';
    return 0;
}
