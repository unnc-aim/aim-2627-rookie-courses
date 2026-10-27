#include <iostream>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);
    std::string::size_type pos = text.find("anon");
    if (pos != std::string::npos)
        text.replace(pos, 4, "saki");
    std::cout << text << '\n';
    return 0;
}
