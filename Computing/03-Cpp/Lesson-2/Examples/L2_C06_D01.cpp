#include <iostream>
#include <string>
#include <utility>

class Band {
  private:
    std::string guitar, vocal, drum, bass, keyboard;

  public:
    Band(std::string gt, std::string vo, std::string dr, std::string ba,
         std::string key) {
        guitar = std::move(gt);
        vocal = std::move(vo);
        drum = std::move(dr);
        bass = std::move(ba);
        keyboard = std::move(key);
    }
    void print_info() const {
        std::cout << guitar << ',' << vocal << ',' << drum << ',' << bass << ','
                  << keyboard << '\n';
    }
    void live() const { std::cout << "LIVE\n"; }
    void get_guitar() const { std::cout << guitar << '\n'; }
    void set_keyboard_anon() { keyboard = "anon"; }
};

int main() {
    Band ave_mujica("mutsumi", "hatsune", "nyamu", "umiri", "saki");
    ave_mujica.print_info();
    ave_mujica.live();
    ave_mujica.get_guitar();
    ave_mujica.set_keyboard_anon();
    ave_mujica.print_info();
    return 0;
}
