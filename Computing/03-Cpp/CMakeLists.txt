cmake_minimum_required(VERSION 3.10)
project(HelloC++)

# --- 设置 C++ 标准 ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- 开启跨平台的编译器警告 ---
# 适用于 MSVC、GCC 和 Clang 的警告设置
if(MSVC)
    # MSVC 编译器警告设置
    add_compile_options(/W3)
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    # GCC 或 Clang 的警告设置
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# --- 添加可执行文件 ---
# executable意为“可执行的”，my_first_cplus是生成的可执行文件名
# 保留往届示例，目录命名与 Python 课程统一。
add_executable(my_first_cplus
        "Lesson-1/my_first_cplus.cpp"
        "Lesson-1/stupid_namespace.cpp"
        "Lesson-1/stupid_namespace.h"
)

# 添加新的可执行文件
add_executable(my_second_cplus
        "Lesson-2/my_second_cpp.cpp"
)

# 本学年讲义配套的完整单文件综合演示。
# Examples 中每个程序各有 main，不能合并到同一个目标。
add_executable(lesson_1_demo "Lesson-1/Demo.cpp")
add_executable(lesson_2_demo "Lesson-2/Demo.cpp")

