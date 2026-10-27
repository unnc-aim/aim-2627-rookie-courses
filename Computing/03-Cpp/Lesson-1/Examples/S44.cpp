#include <cstddef>
#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::size_t begin = 0;
    while (true) {
        std::string::size_type end = s.find(',', begin);
        std::cout << '[' << s.substr(begin, end - begin) << "]\n";
        if (end == std::string::npos)
            break;
        begin = end + 1;
    }
    return 0;
}
