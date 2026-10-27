#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
namespace mygo {
struct std {
    int anon = 42;
};
int cin = 947;
int cout = 310;
} // namespace mygo
void namespace_test() {
    ::std::cout << "namespace " << mygo::cin << ' ' << mygo::cout << '\n';
    mygo::std saki;
    ::std::cout << saki.anon << '\n';
}
void new_new() { std::cout << "Hello, C++! 1\n"; }
void input_int() {
    int x = 0, y = 0;
    std::cin >> x >> y;
    std::cout << "integers " << x << ' ' << y << '\n';
}
void input_variable() {
    double a = 0.0;
    char b = '\0';
    std::string c;
    std::cin >> a >> b >> c;
    std::cout << std::fixed << std::setprecision(2) << a << ' ' << b << ' ' << c
              << '\n';
}
void calculate() {
    std::cout << 3 % 2 << ' ' << 3 / 2 << ' ' << 3.14 / 2 << '\n';
    int x = 10, y = 1;
    std::cout << (y == x) << ' ' << (y <= x) << '\n';
    y = x;
    std::cout << (y != x) << '\n';
    std::cout << (x > 3 && x < 15) << ' ' << !(x > 3 && x < 15) << ' '
              << (y < 3 || y > 15) << '\n';
    std::cout << std::sqrt(2) << ' ' << std::pow(3, 3) << ' ' << std::ceil(2.5)
              << ' ' << std::floor(6.5) << '\n';
    x++;
    x += 5;
    x--;
    std::cout << x << '\n';
}
void if_and_for() {
    int x = 0;
    std::cin >> x;
    if (x > 0)
        std::cout << "POSITIVE\n";
    else if (x < 0)
        std::cout << "NEGATIVE\n";
    else
        std::cout << "ZERO\n";
    for (int i = 1; i <= 5; ++i)
        std::cout << i << '\n';
}
int score[5] = {94, 87, 50};
std::array<int, 5> score_new = {};
void shuzu() {
    for (int value : score)
        std::cout << value << ' ';
    std::cout << '\n';
    int new_scores[] = {80, 85, 90, 95, 100};
    for (int i = 0; i < 5; ++i)
        score[i] = new_scores[i];
    for (int value : score)
        std::cout << value << ' ';
    std::cout << '\n';
    score_new = {1, 2, 3, 4, 5};
    for (int j : score_new)
        std::cout << j << ' ';
    std::cout << '\n';
}
std::string mygo_names = "soyo,anon,taki,rana,tomori";
void str_modern() {
    std::cout << mygo_names.at(3) << '\n';
    std::string::size_type pos = mygo_names.find("anon");
    if (pos != std::string::npos) {
        std::cout << pos << '\n';
        mygo_names.replace(pos, 4, "saki");
    }
    mygo_names += ",bocchi";
    mygo_names.insert(0, "anon,");
    std::string::size_type saki_pos = mygo_names.find("saki,");
    if (saki_pos != std::string::npos)
        mygo_names.erase(saki_pos, 5);
    std::cout << mygo_names << '\n';
    mygo_names.clear();
    std::cout << mygo_names.size() << '\n';
}
int main() {
    namespace_test();
    new_new();
    input_int();
    input_variable();
    calculate();
    if_and_for();
    shuzu();
    str_modern();
}
