#include <string>

class Pet
{
private:
    std::string kind_;
    std::string name_;
    int age_;

public:
    Pet(const std::string &kind, const std::string &name, int age);

    const std::string &name() const;
    const std::string &kind() const;
    int age() const;

    // 唯一的改名入口，校验规则收口在这里
    void rename(const std::string &new_name);

    void print() const;
};
