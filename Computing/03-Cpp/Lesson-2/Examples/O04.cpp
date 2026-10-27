#include <iostream>

class Magazine {
    int rounds_ = 5;

  public:
    bool reload(int n) {
        if (n < 0 || n > 10 - rounds_)
            return false;
        rounds_ += n;
        return true;
    }
    int rounds() const { return rounds_; }
};

int main() {
    Magazine m;
    std::cout << m.reload(4) << ' ' << m.reload(2) << ' ' << m.rounds() << '\n';
    return 0;
}
