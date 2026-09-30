# Python 课程环境准备

本教程将指导你在 Windows 和 macOS 上安装 Python，并配置开发环境。

## Python 本身

> 首先这肯定是最重要的

### 1. 下载 Python

- **Windows**：[Windows Python 3.12.10 官网下载链接](https://www.python.org/ftp/python/3.12.10/python-3.12.10-amd64.exe)
- **macOS**：[macOS Python 3.12.10 官网下载链接](https://www.python.org/ftp/python/3.12.10/python-3.12.10-macos11.pkg)

### 2. 安装步骤

#### Windows

1. 下载并运行安装包。
2. 勾选“Add Python to PATH”选项。
3. 点击“Install Now”完成安装。

#### macOS

1. 下载并打开安装包。
2. 按照提示完成安装。如果有 “Add Python to PATH” 选项，勾选它。

### 3. 验证安装

在命令行输入：

```bash
python --version
# 或
python3 --version
```

显示 Python 版本号即安装成功。

## 推荐 IDE 工具

- [VS Code](https://code.visualstudio.com/)：强大的 Python 编辑器
- [PyCharm](https://www.jetbrains.com/pycharm/)：专业的 Python IDE

> 在课上我们会使用 VS Code 作为示例的代码编辑器。如果对自己的能力有信心，也可以使用 PyCharm。

### Visual Studio Code (IDE)

> 注意：不是 ~~Visual Studio~~，这是完全不同的两个软件，Visual Studio 是微软的一个大型 IDE，主要用于 C#、C++ 等开发。
>
> 几年前如果你说 vscode 是个 `IDE`，不少人会纠正你说，这个只是“轻量级”的「代码编辑器」，但现在它已经非常强大，完全可以胜任 Python 等几乎所有语言的基础开发任务，thanks to 它丰富的插件生态。
>
> 所以叫它 IDE 也没毛病。

#### 安装 VS Code

- **Windows**：[Windows VS Code 官网下载链接](https://code.visualstudio.com/sha/download?build=stable&os=win32-x64-user)
- **macOS**：[macOS VS Code 官网下载链接](https://code.visualstudio.com/sha/download?build=stable&os=darwin-universal)

#### 安装 Python 扩展

1. 打开 VS Code。
2. 点击左侧扩展图标（四个方块组成的图标）。
3. 搜索“Python”，选择由 Microsoft 提供的扩展并安装。(如果提示是否信任，点 `Trust` 即可)

> UNNCers 别老想着装 Chinese 扩展，英文界面更符合编程习惯。
>
> 同时推荐的 Python 相关的拓展组合：
>
> - `ms-python.autopep8` # 自动格式化代码
> - `ms-python.isort` # 自动排序 import 语句
> - `ms-python.vscode-pylance` # 静态代码检查
>
> 以及，为了更好地阅读 Jupyter Notebook 文件（.ipynb），推荐安装以下拓展包
>
> - `ms-toolsai.jupyter` # Jupyter Notebook 支持

### 配置 Python 解释器（简单）

1. 打开一个 Python 文件（.py）。
2. 在右下角点击 Python 版本号，选择刚安装的 Python 解释器路径。
   如果没有看到版本号，可以按 `Ctrl+Shift+P`（macOS 上是 `Cmd+Shift+P`），输入并选择 `Python: Select Interpreter`，然后选择正确的解释器。
3. 现在你可以在 VS Code 中编写和运行 Python 代码了。

### 配置虚拟环境（推荐）

你可能会发现一个问题，如果你直接使用系统的 Python 解释器，可能会遇到权限问题，或者不同项目间的依赖冲突。
为了解决这个问题，我们推荐使用虚拟环境（virtual environment），为每一个项目创建一个定制的运行环境，也可以在每个环境中安装每个项目需要的 pip requirements。
你可以使用 `venv` 模块来创建虚拟环境，VS Code 中具体实现步骤如下：

1. 在右下角点击 Python 版本号，选择 `+ Create Virtual Environment`，然后选 `.venv`。
2. 选择 Python 解释器（你之前安装的版本）作为基础，VS Code 会自动为你创建并激活虚拟环境。

之后你可以在 VS Code 中打开新的终端时，VS Code 会自动帮你激活你项目根目录下的 `.venv` 包含的环境，此时使用 `pip install` 来安装项目所需的包，这些包只会安装在当前虚拟环境中，不会影响全局 Python 环境。

如果你在 VS Code 之外的终端中工作，或者 VS Code 没有正确检测到项目中的 venv 环境，你可能需要手动激活虚拟环境。这部分自己上网搜教程。

然后，你就可以正常打开项目中的 .ipynb 文件，运行里面的代码单元了。
运行时如果提示没有找到内核（kernel），点击选择内核，选择你刚刚配置的 venv 解释器即可。

## 依然，战队规范 Skill (aim-common-rules)

如果你会使用 AI 编程助手（Claude Code / Cursor / Cline / GitHub Copilot 等，见下节）来写课程代码，推荐安装战队规范 skill `aim-common-rules`。装上之后，AI 助手会在**格式化 Python 代码、排序 import、写 commit message** 等场景自动遵循战队规范（autopep8 + isort、PEP 8、行宽 79），和上面推荐的两款扩展保持同一套标准，帮你省去翻文档的时间。

> 前置：`npx` 依赖 Node.js——从 [Node.js 官网](https://nodejs.org/) 下载 **LTS** 版安装（Windows `.msi` / macOS `.pkg`，默认选项即可），命令行 `node -v` 能出版本号就行；macOS 建议顺手执行 `xcode-select --install` 装好 Xcode Command Line Tools。详细说明见根目录 [ENV_SETUP.md](../../ENV_SETUP.md)。

在任意目录执行下面这行即可（`npx skills` 会自动识别并安装到你本地所有 agent —— Claude Code / Cursor / Codex 等）：

```bash
npx skills add unnc-aim/aim-common-agentic-skills --skill aim-common-rules -g
```

`-g` 全局（所有项目，推荐）；不加则装到当前项目。skill 源码与完整规范见 [unnc-aim/aim-common-agentic-skills](https://github.com/unnc-aim/aim-common-agentic-skills)。根目录 [ENV_SETUP.md](../../ENV_SETUP.md) 也有此说明，这里是再次提醒。

## 提示

- 如果你在安装或配置过程中遇到问题，可以参考 [Python 官方文档](https://docs.python.org/3/) 或 [VS Code 官方文档](https://code.visualstudio.com/docs)。
- 你也可以 google 相关问题，通常会有很多有用的资源
- 当然你也可以直接问 AI，比如 ChatGPT 或者直接在 VS Code 中打开 GitHub Copilot Chat 进行提问。
- 重要的是，你要学会先下意识尝试自己解决问题，如果不能解决，再思考如何向人类提出高质量的问题。
