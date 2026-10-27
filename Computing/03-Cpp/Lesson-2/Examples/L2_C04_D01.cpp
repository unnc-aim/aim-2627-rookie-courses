#include <iostream>
#include <string>

struct BandRecord {
    std::string guitar, vocal, bass;
};

int main() {
    BandRecord band = {"mutsumi", "hatsune", "umiri"};
    std::cout << band.guitar << ':' << band.vocal << '\n';
    return 0;
}
