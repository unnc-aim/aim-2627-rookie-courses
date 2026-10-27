#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    long long value = 0;
    while (std::getline(std::cin, line)) {
        std::istringstream in(line);
        std::string op, extra;
        int x = 0;
        if (!(in >> op))
            continue;
        if (op == "ADD" && (in >> x) && !(in >> extra))
            value += x;
        else if (op == "RESET" && !(in >> extra))
            value = 0;
    }
    std::cout << value << '\n';
    return 0;
}
