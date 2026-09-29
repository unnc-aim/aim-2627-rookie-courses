# VirtualBox 安装 Ubuntu 24.04 LTS（Windows）完整安装指南

简明步骤：准备 -> 开启虚拟化 -> 下载并安装 VirtualBox -> 下载 Ubuntu 24.04 ISO -> 新建虚拟机 -> 安装 Ubuntu -> 安装增强功能 -> 常用配置与排错。

## 0. 为什么安装虚拟机？

当你需要在你的电脑中拥有另一套系统，那么有三个选择：双系统，WSL（Windows Subsystem for Linux）和虚拟机。

- 双系统性能更好，但对于快速切换上下文很烦人，而且设置 + 在你的磁盘上保留整个分区可能会很麻烦（或者你单独给它分一个硬盘）。
- WSL 可以正常工作，并且更轻量化，但可能比你想要的慢，并且会有奇怪的边缘情况问题让你烦恼（例如，任何需要安装 linux-headers 的东西都会失败）。最重要的问题是，我们调试需要的一些图形化界面，于是我们需要：
- **虚拟机**。用电脑打游戏的同学应该比较熟悉，可以在你电脑上安装一个小主机，和你的电脑环境隔离~~，有任何问题方便删机跑路~~。

## 1. 开启虚拟化

- 重启进入 BIOS，确认 VT-x（Intel）或 AMD-V（AMD）已开启，多数机器默认开启。
- 若 Windows 开启了 Hyper-V 或「内核隔离（内存完整性）」，VirtualBox 会退化为慢速兼容模式，或报错 `VT-x is being used by another hypervisor`。可在「Windows 功能」与「Windows 安全中心 -> 设备安全性 -> 内核隔离」中关闭后重启（注意：关闭后 WSL2 等功能会不可用，请谨慎操作）。

## 2. 下载并安装 VirtualBox

- 从 VirtualBox 官网下载：[官方地址](https://www.virtualbox.org/wiki/Downloads)，选择 **Windows hosts** 的最新稳定版（7.x）。
- 安装：一路 next 就行。
- VirtualBox 是免费开源软件，**无需许可证密钥**。可选的 Extension Pack（USB 3.0 等高级功能）课程里用不到，不必安装。

## 3. 下载 Ubuntu 24.04 LTS 镜像 .iso 文件

[官方下载地址](https://ubuntu.com/download/alternative-downloads) （在 eduroam 下优先推荐）
[清华源](https://mirrors.tuna.tsinghua.edu.cn/ubuntu-releases/)
[阿里源](https://mirrors.aliyun.com/ubuntu-releases/)

### 版本选择为**Ubuntu 24.04 LTS Desktop（amd64）**

## 4. 创建虚拟机

1. 打开 VirtualBox -> 新建（New）。
2. 名称随意（如 `Ubuntu 24.04`），类型 `Linux`，版本 `Ubuntu (64-bit)`，ISO Image 选择刚下载的 ISO。
3. **勾选 Skip Unattended Installation（跳过无人值守安装）**，这样会进入 Ubuntu 的图形安装界面，与课程演示一致。
4. 硬件配置建议：
   - 内存：4096 MB 起步（建议 8192 MB，之后可以调整）。
   - 处理器：2-4 核（根据主机可用）。
   - 磁盘：40GB 或更大，默认 VDI 动态分配即可。
5. 完成创建后启动虚拟机。

## 5. 在虚拟机中安装 Ubuntu 24.04

1. 启动后进入 Ubuntu 安装界面，语言中文，选择「安装 Ubuntu」。
2. 键盘默认；建议勾选安装第三方软件以支持 Wi-Fi、显卡驱动等。
3. 磁盘使用推荐的「清除整个磁盘并安装 Ubuntu」（这是虚拟磁盘，仅影响 VM）。
4. 设置用户名、密码、时区上海。
5. 安装完成后按提示重启虚拟机。

## 6. 安装增强功能（Guest Additions）

最简方式：虚拟机内打开终端执行以下命令后重启，即提供自适应分辨率、共享剪贴板、拖放等功能：

```bash
sudo apt update && sudo apt install -y virtualbox-guest-utils
```

备选方式：VirtualBox 菜单「设备 -> 安装增强功能」挂载 ISO，先安装编译依赖（`sudo apt install -y build-essential dkms linux-headers-$(uname -r)`），再在挂载目录运行 `sudo ./VBoxLinuxAdditions.run`。

## 7. 常用配置与排错

- 共享剪贴板 / 拖放：先关机，再「设置 -> 常规 -> 高级」把共享剪贴板与拖放改为「双向」（需先装好增强功能）。
- 共享文件夹：「设置 -> 共享文件夹」添加主机目录，勾选自动挂载。
- 网络：默认 NAT 可上网；需要局域网访问（如 SSH 互连）可选「桥接网卡」。
- 启动报 VT-x 错误或运行极慢：见第 1 节，检查 Hyper-V / 内核隔离是否关闭。
- 窗口分辨率不自适应：确认增强功能已安装，再开「视图 -> 自动调整窗口大小」。
- 常用命令：安装常用编译依赖 `sudo apt update && sudo apt install build-essential curl git`
