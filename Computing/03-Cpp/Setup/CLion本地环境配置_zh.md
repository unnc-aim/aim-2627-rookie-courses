# CLion 本地 C++ 环境配置（Windows / macOS）

每位同学使用自己的学校邮箱申请 JetBrains Student Pack 教育授权，再用获得授权的 JetBrains 账号激活 CLion。准备好本地环境后，运行一个 Hello World 即完成配置。

## 1. 用学校邮箱申请学生授权

### 第一步：准备学校邮箱

确认自己能正常登录学校邮箱并收信。申请时填写完整学校邮箱地址，不是只填写学号；后续的验证和授权通知需要在邮箱中处理。

### 第二步：打开 Student Pack 页面并点击 Apply

打开 [JetBrains Student Pack 学生申请页面](https://www.jetbrains.com/academy/student-pack/)，点击页面上的 Apply 或 Apply now，进入学生授权申请流程。

如果页面先要求登录 JetBrains Account：已有账号就登录；没有账号则按页面提示注册，建议使用学校邮箱。完成后继续原来的学生申请。注册账号本身还不等于已经取得学生授权。

### 第三步：填写学生申请

按页面提示选择学生身份，使用学校邮箱进行申请或资格验证，并如实填写要求的姓名、学校等信息。核对学校邮箱拼写后提交。如果页面要求补充在读信息，按其提示完成。

### 第四步：处理学校邮箱中的邮件

提交后打开学校邮箱，查看 JetBrains 发来的验证邮件并点击其中的确认链接。没有看到邮件时，检查垃圾邮件，并确认申请时填写的邮箱是否正确。

继续按照邮件和网页提示完成申请。邮箱验证后如果页面仍显示审核中，就等待审核结果；不要把“已提交申请”当成“授权已经生效”。

### 第五步：确认授权已关联到账号

收到通过或激活通知后，按邮件链接登录 [JetBrains Account](https://account.jetbrains.com/)，完成授权关联。确认账号中已有可用于 CLion 的学生教育授权。

记住这个 JetBrains 账号，后面 CLion 里要登录同一个账号。若申请过程中使用了已有账号，授权可能关联在该账号下，不要激活时又换成另一账号。

## 2. 下载并安装 CLion

打开 [CLion 官方下载页](https://www.jetbrains.com/clion/download/)，选择电脑对应的系统和安装包。

**Windows：** 下载 Windows 安装程序，打开后按安装向导完成安装。安装结束后启动 CLion。

**macOS：** 先在苹果菜单的“关于本机”查看芯片。M 系列芯片选择 Apple Silicon，Intel 处理器选择 Intel。下载后打开安装镜像，把 CLion 拖到 Applications（应用程序）文件夹，再从该文件夹启动。

## 3. 在 CLion 中激活学生授权

1. 首次启动出现授权窗口时，选择登录 JetBrains Account。
2. 登录第 1 节中已经取得学生授权的那个账号，按浏览器提示完成登录并返回 CLion。
3. 在可用授权中选择学生教育授权，按界面提示激活。
4. 如果已经进入欢迎页，可从 Manage Licenses 打开授权窗口；已经打开项目时，可从 Help > Manage Subscriptions 查找。不同版本的菜单名称可能略有不同。

如果显示没有可用授权，先核对登录账号、查看申请是否获批，再尝试刷新授权列表。此时应先完成授权申请和关联，而不是反复重新安装软件。

## 4. 准备编译工具

**Windows：** 使用 CLion 内置 MinGW。若首次打开时要求选择工具链，选择 MinGW，再选择 Bundled MinGW，等待编译器自动识别。若没有自动弹出，可在设置中搜索 Toolchains 找到该选项。

**macOS：** 打开系统“终端”，执行下面的命令，并在弹窗中完成 Command Line Tools 安装。等待安装结束后再回到 CLion；已经安装过则跳过。

```bash
xcode-select --install
```

安装完成后，CLion 使用自动识别的 Apple Clang。

## 5. 新建程序，运行 Hello World

1. 在 CLion 欢迎页点击 New Project。
2. 选择 C++ Executable，语言标准选择 C++17，选择一个本地文件夹并创建项目。
3. 等待项目加载完成，打开自动生成的 main.cpp，把原内容替换为：

```cpp
#include <iostream>

int main() {
    std::cout << "Hello World\n";
    return 0;
}
```

也可以复制本指南附带的 hello.cpp 中的代码。

点击 main 函数旁的绿色运行按钮，或选择当前项目后点击右上角 Run。第一次运行会先编译，等待它完成。

在下方 Run 窗口看到下面这一行，就说明本地环境配置完成：

```text
Hello World
```

本程序不需要输入任何数据。

参考入口：[Student Pack 申请](https://www.jetbrains.com/academy/student-pack/)、[CLion 授权激活](https://www.jetbrains.com/help/clion/register.html)、[Windows 编译器配置](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-windows.html)、[macOS 开发工具](https://www.jetbrains.com/help/clion/quick-tutorial-on-configuring-clion-on-macos.html)。
