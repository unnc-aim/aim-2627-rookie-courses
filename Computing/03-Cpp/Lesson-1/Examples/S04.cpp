#include <iostream>
#include <string>

int main() {
    std::string name;
    std::getline(std::cin, name);
    std::cout << '[' << name << "]\n";
    return 0;
}
