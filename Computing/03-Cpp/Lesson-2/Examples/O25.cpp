#include <iostream>
#include <string>
#include <vector>

class Diagnostics {
    std::vector<std::string> messages_;

  public:
    void add(const std::string &s) {
        if (!s.empty())
            messages_.push_back(s);
    }
    void report() const {
        for (const std::string & s : messages_)
            std::cout << s << '\n';
    }
};

int main() {
    Diagnostics d;
    d.add("OK");
    d.add("");
    d.add("LOW");
    d.report();
    return 0;
}
