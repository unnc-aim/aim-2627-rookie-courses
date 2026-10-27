#include <iostream>
#include <string>

int main() {
    std::string mygo = "soyo,anon,taki,rana,tomori";
    std::string::size_type pos = mygo.find("anon");
    if (pos != std::string::npos) {
        std::cout << pos << '\n';
    }
    std::cout << std::boolalpha << (mygo.find("saki") == std::string::npos) << '\n';
    return 0;
}
