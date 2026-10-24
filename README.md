# LeetCode C++ Solutions

一个使用 C++20 编写的 LeetCode 题解仓库。每道题都是独立的可执行程序，源码内包含轻量测试，统一通过 CMake 和 CTest 构建、运行。

## 项目结构

```text
.
├── CMakeLists.txt
├── include/
│   ├── common.h            # 公共工具兼容入口
│   ├── compare_helper.h    # 无序容器比较
│   ├── list_helper.h       # 链表节点与辅助函数
│   ├── test_helper.h       # 始终生效的 CHECK 断言
│   └── tree_helper.h       # 二叉树节点与辅助函数
└── src/
    ├── 1-twoSum.cpp
    └── 401-readBinaryWatch.cpp
```

源码文件使用 `题号-题目名.cpp` 命名，并生成同名可执行目标。

## 环境要求

- CMake 3.21 或更高版本
- 支持 C++20 的 GCC 或 Clang
- Linux 或 macOS

## 构建与测试

Debug 构建：

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --parallel 8
ctest --test-dir build --parallel 8 --output-on-failure
```

Release 构建使用独立目录，测试仍会执行全部 `CHECK` 校验：

```bash
cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
cmake --build build-release --parallel 8
ctest --test-dir build-release --parallel 8 --output-on-failure
```

## 构建和运行单题

以 `394-decodeString` 为例：

```bash
cmake --build build --target 394-decodeString
./build/394-decodeString
ctest --test-dir build -R '^394-decodeString$' --output-on-failure
```

## 添加新题目

1. 在 `src/` 中新增 `题号-题目名.cpp`。
2. 保留题目的 `Solution` 接口，并使用 `CHECK` 编写测试。
3. 根据实际使用引入精确的标准库头文件；链表、树或无序比较可复用 `include/` 中的辅助工具。
4. 重新构建。CMake 会自动发现源码并创建同名可执行目标和 CTest 测试。

## 持续集成

GitHub Actions 会分别在 Linux/GCC Debug 和 macOS/Clang Release 环境中构建全部题目，并运行 108 个 CTest 测试。

## 参考

- [LeetCode](https://leetcode.cn/)
- [CMake 文档](https://cmake.org/documentation/)
- [CTest 文档](https://cmake.org/cmake/help/latest/manual/ctest.1.html)
