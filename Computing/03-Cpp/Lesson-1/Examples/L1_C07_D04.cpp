#include <iostream>
#include <string>

int main() {
    std::string text = "soyo,saki,taki";
    text += ",rana";
    text.insert(0, "anon,");
    std::string::size_type pos = text.find("saki,");
    if (pos != std::string::npos) {
        text.erase(pos, 5);
    }
    std::cout << text << '\n';
    text.clear();
    std::cout << text.size() << '\n';
    return 0;
}
