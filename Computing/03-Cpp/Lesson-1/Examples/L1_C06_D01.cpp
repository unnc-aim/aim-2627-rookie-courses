#include <iostream>

int main() {
    int score[5] = {94, 87, 50};
    for (int i = 0; i < 5; ++i) {
        std::cout << i << ':' << score[i] << '\n';
    }
    return 0;
}
