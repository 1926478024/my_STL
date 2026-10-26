# Smart_ptr — C++ 智能指针实现

从零实现 `Shared_ptr`、`Unique_ptr`、`Weak_ptr`，覆盖所有权管理、弱引用观察与循环引用破解。

## 文件结构

```
Smart_ptr/
├── Smart_ptr.h   # 三种智能指针的模板实现
├── main.cpp      # 基本用法与循环引用验证
├── Makefile
└── README.md
```

## 编译运行

```bash
make       #编译

make run   #运行

make clean #清除
```

## 实现内容

### Shared_ptr

共享所有权的智能指针，内部维护引用计数控制块。

- 拷贝构造 / 拷贝赋值：强引用计数 +1
- 移动构造 / 移动赋值：所有权转移，不改动计数
- `get()` / `operator*` / `operator->` / `use_count()` / `reset()`
- 最后一个强引用释放时删除对象；若此时弱引用也为 0，则释放控制块

### Unique_ptr

独占所有权的智能指针。

- 拷贝操作被 `delete`，保证唯一所有权
- 支持移动构造 / 移动赋值
- 析构时自动 `delete` 所管理的对象

### Weak_ptr

不拥有对象，只观察，**不增加强引用计数**。

- 只能从 `Shared_ptr` 或另一个 `Weak_ptr` 构造，不可从裸指针构造
- `lock()`：若对象仍存活，提升为 `Shared_ptr`；否则返回空
- `expired()`：判断观察对象是否已被释放
- 最后一个弱引用释放且强引用已为 0 时，释放控制块

## 关键设计

### 控制块生命周期

| 阶段 | strong | weak | 控制块 |
|---|---|---|---|
| 创建 Shared_ptr | 1 | 0 | 存活 |
| 被 Weak_ptr 观察 | 1 | 1 | 存活 |
| 最后一个 Shared_ptr 析构 | 0 | 1 | 存活，对象已删除 |
| 最后一个 Weak_ptr 析构 | 0 | 0 | 释放 |

## 已知限制

- 未实现自定义删除器（`Deleter`）
- 未实现 `enable_shared_from_this`
- 未实现 `make_shared` / `make_unique`
- 控制块为两个独立 `long*`，非线程安全
- 未实现数组特化（`Shared_ptr<T[]>`）
