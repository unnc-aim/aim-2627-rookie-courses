// answer_subject.cpp —— 第一篇练习参考实现：Subject（学科）类
//
// 编译：g++ -std=c++17 -Wall -Wextra -o answer_subject answer_subject.cpp
// 运行：./answer_subject
//
// 要点：
//   - 私有成员 name_ / teacher_ / hours_ 封装内部状态
//   - 构造函数使用初始化列表，保证对象一创建就有合法初始值
//   - 只读访问器与 print() 均标为 const，支持 const 引用传参
//   - set_hours() 统一拦截非法负数课时

#include <iostream>
#include <string>

class Subject
{
private:
    std::string name_;    // 学科名
    std::string teacher_; // 任课老师
    int hours_;           // 课时数

public:
    Subject(const std::string &name, const std::string &teacher, int hours)
        : name_(name), teacher_(teacher), hours_(hours)
    {
    }

    const std::string &name() const { return name_; }
    const std::string &teacher() const { return teacher_; }
    int hours() const { return hours_; }

    // 唯一修改入口：拒绝负数课时
    void set_hours(int hours)
    {
        if (hours < 0)
        {
            std::cout << "!! negative hours rejected\n";
            return;
        }
        hours_ = hours;
    }

    void print() const
    {
        std::cout << name_ << " | " << teacher_ << " | " << hours_ << " h\n";
    }
};

// 按 const 引用接收对象：不拷贝，且保证只读（依赖 print() 是 const 成员函数）
void describe(const Subject &subject)
{
    subject.print();
}

int main()
{
    Subject cs("Computer Science", "Prof. Wang", 64);
    Subject math("Mathematics", "Prof. Li", 48);

    describe(cs);
    describe(math);

    std::cout << "---- after updating cs hours ----\n";
    cs.set_hours(96);
    cs.set_hours(-10); // 被拒绝

    describe(cs);
    describe(math); // math 与 cs 各自独立，不受影响

    // 下面这行无法编译，因为 hours_ 是 private：
    //   cs.hours_ = 1000;

    return 0;
}
