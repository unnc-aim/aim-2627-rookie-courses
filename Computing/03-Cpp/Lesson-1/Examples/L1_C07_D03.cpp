#include <iostream>
#include <string>

int main() {
    std::string mygo = "soyo,anon,taki,rana,tomori";
    std::string::size_type pos = mygo.find("anon");
    if (pos != std::string::npos) {
        mygo.replace(pos, 4, "saki");
    }
    std::cout << mygo << '\n';
    return 0;
}
