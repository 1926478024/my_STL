# C++ 算法与数据结构实现

## 项目简介

本项目集合了多个 C++ 算法与数据结构的独立实现，每个模块以独立文件夹组织，包含自己的源码、编译配置和说明文档。

## 目录结构

```
├── README.md                # 本文件（项目总览）
├── Vector/                  # Vector 模板动态数组
│   ├── README.md
│   ├── Vector.h
│   ├── main.cpp
│   └── Makefile
├── Sorting/                 # 排序算法实现
│   ├── README.md
│   ├── Sort.h
│   ├── main.cpp
│   └── Makefile
├── [其他模块名]/            # 新增模块目录
│   ├── README.md
│   └── ...
└── ...
```

## 子模块说明

| 模块 | 说明 | 文档 |
|------|------|------|
| Vector | 基于模板的 C++ 动态数组实现，支持泛型编程 | [Vector/README.md](Vector/README.md) |
| Sorting | 排序算法实现（冒泡、选择、插入、快速、归并等） | [Sorting/README.md](Sorting/README.md) |
| [模块名] | [模块描述] | [链接](模块文件夹/README.md) |

> 每新增一个模块，只需在本表的最后一行追加一行，并在项目根目录下创建对应的文件夹即可。

## 通用编译方式

每个子模块文件夹内都包含独立的 `Makefile`，进入对应目录后执行：

```bash
cd Vector          # 进入模块目录
make               # 编译
make run           # 编译并运行
make clean         # 清理编译产物
```

也可以直接使用 g++ 编译（具体命令见各模块的 README.md）：

```bash
g++ -std=c++11 main.cpp -o main
./main
```

## 技术栈

- **语言**：C++11
- **构建工具**：Make
- **编译器**：g++

## 注意事项

- 各模块之间相互独立，互不依赖
- 模板类的实现统一放在头文件（`.h`）中，遵循标准库的实现方式
