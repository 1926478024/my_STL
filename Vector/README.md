# Vector - C++ 模板动态数组实现

## 项目简介

本项目实现了一个基于模板的 C++ 动态数组类 `Vector`，支持泛型编程，可存储任意类型的元素。

## 文件结构

```
├── Vector.h      # Vector 模板类声明与实现（头文件）
├── main.cpp      # 主程序入口
└── Makefile      # 编译配置
```

## 编译与运行

### 使用 Makefile

```bash
make          # 编译
make run      # 编译并运行
make clean    # 清理编译产物
```

### 使用 g++ 直接编译

```bash
g++ -std=c++11 main.cpp -o main
./main
```

## 技术要点

- **模板类**：`Vector<T>` 使用模板参数 `T`，支持 `int`、`double`、`string` 等任意类型
- **头文件实现**：模板的声明与实现均放在 `Vector.h` 中，编译器在每个使用点自动实例化，无需显式实例化
- **C++11 标准**：使用 `-std=c++11` 编译

## 注意事项

- 模板类的实现必须放在头文件中（`.h`），不能单独放在 `.cpp` 文件中，否则链接时会报 `undefined reference` 错误
- 这与标准库（如 `std::vector`）的实现方式一致——标准库的模板实现全部在头文件里
