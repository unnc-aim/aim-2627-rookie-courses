// answer_course.cpp —— 第二篇练习 2 参考实现：多态 Course 课程体系
//
// 编译：g++ -std=c++17 -Wall -Wextra -o answer_course answer_course.cpp
// 运行：./answer_course
//
// 要点：
//   - 抽象基类 Course 封装共有字段与 set_hours() 校验
//   - 纯虚函数 credits() 和 print() 强制子类各自实现
//   - LectureCourse（16 课时/学分）与 LabCourse（32 课时/学分 + 实验室号）公有继承 Course
//   - print_syllabus() 通过 std::unique_ptr<Course> 统一打印并汇总总学分

#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Course
{
private:
    std::string name_;
    std::string teacher_;
    int hours_;

public:
    Course(const std::string &name, const std::string &teacher, int hours)
        : name_(name),
          teacher_(teacher),
          hours_(hours < 0 ? 0 : hours)
    {
    }

    virtual ~Course() = default;

    const std::string &name() const { return name_; }
    const std::string &teacher() const { return teacher_; }
    int hours() const { return hours_; }

    void set_hours(int hours)
    {
        if (hours < 0)
        {
            std::cout << "!! negative hours rejected\n";
            return;
        }
        hours_ = hours;
    }

    virtual double credits() const = 0;
    virtual void print() const = 0;
};

class LectureCourse : public Course
{
public:
    LectureCourse(const std::string &name, const std::string &teacher, int hours)
        : Course(name, teacher, hours)
    {
    }

    double credits() const override
    {
        return hours() / 16.0;
    }

    void print() const override
    {
        std::cout << "[Lecture] " << name()
                  << " | " << teacher()
                  << " | " << hours() << " h"
                  << " | " << credits() << " credits\n";
    }
};

class LabCourse : public Course
{
private:
    std::string lab_room_;

public:
    LabCourse(const std::string &name, const std::string &teacher, int hours, const std::string &lab_room)
        : Course(name, teacher, hours),
          lab_room_(lab_room)
    {
    }

    const std::string &lab_room() const { return lab_room_; }

    double credits() const override
    {
        return hours() / 32.0;
    }

    void print() const override
    {
        std::cout << "[Lab]     " << name()
                  << " | " << teacher()
                  << " | " << hours() << " h"
                  << " | room " << lab_room_
                  << " | " << credits() << " credits\n";
    }
};

void print_syllabus(const std::vector<std::unique_ptr<Course>> &courses)
{
    double total_credits = 0.0;
    std::cout << std::fixed << std::setprecision(1);

    for (const auto &course : courses)
    {
        course->print();
        total_credits += course->credits();
    }

    std::cout << "----------------\n";
    std::cout << "Total credits: " << total_credits << '\n';
}

int main()
{
    std::vector<std::unique_ptr<Course>> courses;
    courses.push_back(std::make_unique<LectureCourse>("Computer Science", "Prof. Wang", 64));
    courses.push_back(std::make_unique<LectureCourse>("Mathematics", "Prof. Li", 48));
    courses.push_back(std::make_unique<LabCourse>("C++ Programming Lab", "Dr. Zhang", 32, "B-302"));

    print_syllabus(courses);

    std::cout << "---- try invalid hours ----\n";
    courses[0]->set_hours(-8); // 负数会被拒绝

    // 下面这行无法编译，因为 Course 是抽象类：
    //   Course c("Physics", "Prof. Zhao", 32);

    return 0;
}
