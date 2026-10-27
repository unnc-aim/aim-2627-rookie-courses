#include <iostream>

struct Counter {
    int value = 0;
};
void touch_copy(Counter c) { ++c.value; }
void touch_ref(Counter &c) { ++c.value; }

int main() {
    Counter c;
    touch_copy(c);
    touch_ref(c);
    std::cout << c.value << '\n';
    return 0;
}
