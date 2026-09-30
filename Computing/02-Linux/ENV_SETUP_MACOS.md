# VirtualBox 安装 Ubuntu 24.04 LTS（macOS）完整安装指南

简明步骤：确认芯片架构 -> 下载并安装 VirtualBox -> 下载 Ubuntu 24.04 ISO -> 新建虚拟机 -> 安装 Ubuntu -> 安装增强功能 -> 常用配置与排错。

## 0. 为什么在 macOS 上用 VirtualBox？

当你需要在 mac 上运行另一套完整 Linux 系统，有几种选择：双系统（Boot Camp，只限 Intel）、容器/WSL（不适用于 macOS）和虚拟机。
VirtualBox 的优点：免费开源、无需订阅或密钥，并且与 Windows 侧队友使用同一套工具，遇到问题时互相能对上话。

**先确认你的芯片**（苹果菜单 -> 关于本机 -> 查看芯片）——VirtualBox 官网为 macOS 提供 Intel 与 Apple Silicon 两个安装包，下载对应的版本即可：

- **Intel（x86_64）**：下载 "macOS / Intel hosts"，虚拟机使用 amd64 镜像。
- **Apple Silicon（M1-M4 等 ARM 芯片）**：下载 "macOS / Apple Silicon hosts"，虚拟机使用 arm64 镜像。

## 1. 下载并安装 VirtualBox

- 从 VirtualBox 官网下载：[官方地址](https://www.virtualbox.org/wiki/Downloads)，在 Platform packages 中按芯片选择 **macOS / Intel hosts** 或 **macOS / Apple Silicon hosts** 的最新稳定版（7.x），得到 .dmg 安装包。
- 双击 .dmg 按提示安装；首次运行若被系统拦截，在「系统设置 -> 隐私与安全性」中点击「仍要打开」并允许 VirtualBox 请求的权限。

注意：macOS 上无需开启 BIOS 虚拟化（这是 PC 的操作）。

## 2. 下载 Ubuntu 镜像（ISO）

- **Ubuntu 24.04 LTS Desktop**，按芯片选架构：Intel 选 amd64（x86_64），Apple Silicon 选 arm64（aarch64）
- amd64 镜像下载：
   - 官方：<https://ubuntu.com/download/alternative-downloads>
   - 清华：<https://mirrors.tuna.tsinghua.edu.cn/ubuntu-releases/>
   - 阿里：<https://mirrors.aliyun.com/ubuntu-releases/>
- arm64 Desktop 镜像在 cdimage 发布：
   - 官方：<https://cdimage.ubuntu.com/releases/>
   - 清华：<https://mirrors.tuna.tsinghua.edu.cn/ubuntu-cdimage/releases/>
- 校验 ISO：建议比对 SHA256 校验和以确认下载完整。

## 3. 创建虚拟机

1. 打开 VirtualBox -> 新建（New）。
2. 名称随意（如 `Ubuntu 24.04`），类型 `Linux`，版本选择 Ubuntu（Intel 为 `Ubuntu (64-bit)`，Apple Silicon 选对应的 Arm 版本），ISO Image 选择刚下载的 ISO。
3. **勾选 Skip Unattended Installation（跳过无人值守安装）**，这样会进入 Ubuntu 的图形安装界面，与课程演示一致。
4. 硬件配置建议：
   - 内存：4096 MB 起步（开发/编译建议 8192 MB）。
   - 处理器：2-4 核（取决于主机资源）。
   - 磁盘：40GB 或更大，默认 VDI 动态分配即可。
5. 完成创建后启动虚拟机。

## 4. 在虚拟机中安装 Ubuntu 24.04

1. 启动虚拟机后进入 Ubuntu 安装界面，语言中文，选择「安装 Ubuntu」。
2. 键盘默认；建议勾选安装第三方软件以支持 Wi-Fi、显卡驱动等。
3. 分区：使用推荐的「清除整个磁盘并安装 Ubuntu」（这是虚拟磁盘，仅影响 VM）。
4. 设置用户名、密码、时区（例如上海）。
5. 等待安装完成，按提示重启虚拟机。

## 5. 安装增强功能（Guest Additions）

最简方式：虚拟机内打开终端执行以下命令后重启，即提供自适应分辨率、共享剪贴板、拖放等功能：

```bash
sudo apt update && sudo apt install -y virtualbox-guest-utils
```

备选方式：VirtualBox 菜单「设备 -> 安装增强功能」挂载 ISO，先安装编译依赖（`sudo apt install -y build-essential dkms linux-headers-$(uname -r)`），再在挂载目录运行 `sudo ./VBoxLinuxAdditions.run`。

## 6. 常用配置与排错

- 共享剪贴板 / 拖放：先关机，再「设置 -> 常规 -> 高级」把共享剪贴板与拖放改为「双向」（需先装好增强功能）。
- 共享文件夹：「设置 -> 共享文件夹」添加主机目录，勾选自动挂载。
- 分辨率 / 全屏：安装增强功能后自动工作；手动可调「视图 -> 虚拟屏幕」。
- 网络问题：默认 NAT 可上网；需要局域网访问可选「桥接网卡」，并检查 mac 防火墙设置。
- VirtualBox 权限提示：在「系统设置 -> 隐私与安全性」中允许 VirtualBox 的相关权限和扩展。
- 性能优化：关闭不需要的 macOS 应用，增加 VM 内存/CPU，使用 SSD 存储 VM 文件。
- 常用命令：安装常用编译依赖 `sudo apt update && sudo apt install build-essential curl git`

结束语：按以上步骤，Intel 与 Apple Silicon Mac 都可以通过 VirtualBox 搭建 Ubuntu 24.04 LTS 虚拟机——关键是安装包和镜像都按芯片选对架构。如遇特定错误，把错误信息贴出来可进一步定位解决方法。
