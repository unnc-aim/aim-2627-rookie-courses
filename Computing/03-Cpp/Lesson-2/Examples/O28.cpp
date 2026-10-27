#include <iostream>

class Base {
  protected:
    int hp_ = 10;

  public:
    int hp() const { return hp_; }
};
class Derived : public Base {
  public:
    void damage() { hp_ -= 3; }
};

int main() {
    Derived d;
    d.damage();
    std::cout << d.hp() << '\n';
    return 0;
}
