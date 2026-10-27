#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Log {
    std::vector<std::string> data_;

  public:
    void add(std::string s) { data_.push_back(std::move(s)); }
    std::size_t size() const { return data_.size(); }
};

int main() {
    Log a;
    a.add("start");
    Log b = a;
    b.add("stop");
    std::cout << a.size() << ' ' << b.size() << '\n';
    return 0;
}
