# Windsurf C++（Windows）编译/安装说明

本文档以本仓库的目录结构为例，说明如何在 **Windsurf IDE** 中配置并编译运行 C++（使用 **MSYS2 + MinGW-w64 g++**）。

## 1. 安装编译器（MSYS2 + MinGW-w64）

1) 安装 MSYS2：<https://www.msys2.org/>

2) 打开 **MSYS2 MinGW x64** 终端，更新与安装工具链：

```bash
pacman -Syu
# 关闭终端后重新打开（按提示）

pacman -S --needed mingw-w64-x86_64-toolchain
```

1) 确认 `g++` 可用：

```bash
g++ --version
```

## 2. 配置 PATH（让 Windsurf 找到 g++）

确保以下目录在系统环境变量 `PATH` 中（以默认安装为例）：

- `C:\msys64\mingw64\bin`

配置完成后，重启 Windsurf。

## 3. 在 Windsurf 中编译（单文件）

在本仓库根目录（例如 `d:\C-Code`）打开终端，使用如下命令编译：

```bash
g++ -std=c++17 -g -O0 -Wall -Wextra -Wpedantic hello_world.cpp -o hello_world.exe
```

运行：

```bash
./hello_world.exe
```

## 4. 常用编译指令模板（推荐）

- 调试版（适合学习/调试）：

```bash
g++ -std=c++17 -g -O0 -Wall -Wextra -Wpedantic <input>.cpp -o <output>.exe
```

- 发布版（更高优化）：

```bash
g++ -std=c++17 -O2 -DNDEBUG -Wall -Wextra -Wpedantic <input>.cpp -o <output>.exe
```

## 5. 编译本仓库示例（示例文件名）

在 `d:\C-Code` 目录下，你可以这样编译各示例：

```bash
g++ -std=c++17 -g -O0 -Wall -Wextra -Wpedantic floating_point_io.cpp -o floating_point_io.exe

g++ -std=c++17 -g -O0 -Wall -Wextra -Wpedantic stream_formatting.cpp -o stream_formatting.exe

g++ -std=c++17 -g -O0 -Wall -Wextra -Wpedantic default_parameters.cpp -o default_parameters.exe

g++ -std=c++17 -g -O0 -Wall -Wextra -Wpedantic function_overloading.cpp -o function_overloading.exe
```

## 6. （可选）在 Windsurf 中配置一键任务（tasks.json）

如果你使用 VSCode 风格的任务（Windsurf 支持类似配置），可以在 `.vscode/tasks.json` 中配置一个通用任务，参数里替换当前文件名。

常见做法是：

- 任务：调用 `g++` 编译当前打开的 `.cpp`
- 输出：生成同名 `.exe`

具体字段会因你的 Windsurf/VSCode 配置略有不同；核心编译命令就是本文件中的 `g++` 模板。

## 7. 常见问题

- **找不到 g++**：说明 PATH 未配置或未重启 Windsurf。检查 `C:\msys64\mingw64\bin` 是否在 PATH。
- **push 到 GitHub 报网络错误**：通常与网络/代理有关，与编译无关。
