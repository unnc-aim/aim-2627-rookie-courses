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

int main() {
    Band basic("mutsumi", "hatsune", "nyamu", "umiri", "saki");
    basic.print_info();
    basic.set_keyboard_anon();
    basic.print_info();
    MofoBand_New derived("toko", "mashiro", "tsukushi", "nanami", "rui", "amane");
    derived.change_actor("ayane");
    derived.print_mofo_info();
    return 0;
}
