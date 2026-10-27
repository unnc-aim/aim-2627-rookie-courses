#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream stream(line);
    int value = 0;
    char extra = '\0';
    if ((stream >> value) && !(stream >> extra))
        std::cout << value << '\n';
    else
        std::cout << "INVALID\n";
    return 0;
}
