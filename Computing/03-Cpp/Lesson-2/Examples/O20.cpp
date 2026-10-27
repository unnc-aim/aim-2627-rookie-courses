#include <iostream>

class Tracker {
  public:
    inline static int live = 0;
    Tracker() { ++live; }
    Tracker(const Tracker &) { ++live; }
    ~Tracker() { --live; }
};

int main() {
    {
        Tracker a;
        Tracker b = a;
        std::cout << Tracker::live << '\n';
    }
    std::cout << Tracker::live << '\n';
    return 0;
}
