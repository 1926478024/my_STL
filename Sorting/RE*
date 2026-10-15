# 排序算法模块

## 简介

本模块包含 7 种经典排序算法的 C++ 实现，均基于 `std::vector<int>` 原地排序（归并排序使用辅助数组）。

## 算法清单

| 算法 | 平均时间复杂度 | 最坏时间复杂度 | 空间复杂度 | 稳定性 |
|---|---|---|---|---|
| 冒泡排序 | O(n²) | O(n²) | O(1) | 稳定 |
| 插入排序 | O(n²) | O(n²) | O(1) | 稳定 |
| 选择排序 | O(n²) | O(n²) | O(1) | 不稳定 |
| 希尔排序 | O(n log n) ~ O(n²) | O(n²) | O(1) | 不稳定 |
| 快速排序 | O(n log n) | O(n²) | O(log n) | 不稳定 |
| 堆排序 | O(n log n) | O(n log n) | O(1) | 不稳定 |
| 归并排序 | O(n log n) | O(n log n) | O(n) | 稳定 |

## 文件结构
sorting/
├── README.md
├── sort.h # 所有排序算法的实现
├── Makefile
└── main.cpp # 测试入口


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

