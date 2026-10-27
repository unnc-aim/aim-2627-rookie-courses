#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line, word;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int count = 0;
    while (stream >> word)
        ++count;
    std::cout << count << '\n';
    return 0;
}
