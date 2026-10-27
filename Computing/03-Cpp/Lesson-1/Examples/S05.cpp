#include <iostream>
#include <string>

int main() {
    int id = 0;
    std::string name;
    std::cin >> id;
    std::getline(std::cin >> std::ws, name);
    std::cout << id << ':' << name << '\n';
    return 0;
}
