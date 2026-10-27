#include <iostream>

class Robot {
  public:
    int id() const { return 7; }
};
class Sentry : public Robot {
  public:
    void patrol() const { std::cout << "PATROL\n"; }
};

int main() {
    Sentry s;
    std::cout << s.id() << '\n';
    s.patrol();
    return 0;
}
