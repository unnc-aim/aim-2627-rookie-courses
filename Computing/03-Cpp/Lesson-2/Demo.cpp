#include <iostream>
#include <string>
#include <utility>
#include <vector>
int test_add(int a, int b) {
    int sum = a + b;
    return sum;
}
void cite_pointer() {
    std::string band1 = "poppin party";
    std::string &live1 = band1;
    std::cout << std::boolalpha << (&band1 == &live1) << '\n';
    std::string *anime1 = nullptr;
    anime1 = &band1;
    std::cout << *anime1 << '\n';
    *anime1 = "afterglow";
    std::cout << band1 << '\n';
}
void swap1(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
void swap2(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
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
class MofoBand : public Band {
  protected:
    std::string vocal_actor;

  public:
    MofoBand(std::string gt, std::string vo, std::string dr, std::string ba,
             std::string key, std::string actor)
        : Band(std::move(gt), std::move(vo), std::move(dr), std::move(ba),
               std::move(key)),
          vocal_actor(std::move(actor)) {}
    void print_mofo_info() const {
        print_info();
        std::cout << vocal_actor << '\n';
    }
};
class MofoBand_New : public MofoBand {
  public:
    MofoBand_New(std::string gt, std::string vo, std::string dr, std::string ba,
                 std::string key, std::string actor)
        : MofoBand(std::move(gt), std::move(vo), std::move(dr), std::move(ba),
                   std::move(key), std::move(actor)) {}
    void change_actor(const std::string &new_actor) {
        this->vocal_actor = new_actor;
    }
};
void class_band() {
    Band ave_mujica("mutsumi", "hatsune", "nyamu", "umiri", "saki");
    ave_mujica.print_info();
    ave_mujica.live();
    std::vector<Band> live_bands;
    live_bands.emplace_back("hina", "aya", "maya", "chisato", "eve");
    live_bands.emplace_back("sayo", "yukina", "ako", "lisa", "rinko");
    for (Band &p : live_bands)
        p.print_info();
    ave_mujica.get_guitar();
    ave_mujica.set_keyboard_anon();
    ave_mujica.print_info();
    MofoBand morfonica("toko", "mashiro", "tsukushi", "nanami", "rui", "amane");
    morfonica.print_mofo_info();
    MofoBand_New lovelive("toko", "mashiro", "tsukushi", "nanami", "rui", "amane");
    lovelive.change_actor("ayane");
    lovelive.print_mofo_info();
}
int main() {
    std::cout << test_add(1, 2) << '\n';
    cite_pointer();
    int a = 10, b = 20;
    swap1(a, b);
    std::cout << a << ' ' << b << '\n';
    swap2(&a, &b);
    std::cout << a << ' ' << b << '\n';
    class_band();
}
