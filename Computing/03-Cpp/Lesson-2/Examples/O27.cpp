#include <iostream>

class Robot {
    int id_;

  public:
    explicit Robot(int id) : id_(id) {}
    int id() const { return id_; }
};
class Sentry : public Robot {
  public:
    explicit Sentry(int id) : Robot(id) {}
};

int main() {
    Sentry s(9);
    std::cout << s.id() << '\n';
    return 0;
}
