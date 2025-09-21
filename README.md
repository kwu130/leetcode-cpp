# LeetCode C++ Solutions

一个使用 **C++** 编写的 LeetCode 算法题解答仓库，统一使用 **CMake**
进行构建和管理。

------------------------------------------------------------------------

## 📂 项目结构

    .
    ├── CMakeLists.txt       # 顶层 CMake 构建文件
    ├── src/                 # 各题目源码
    │   ├── 1-twoSum.cpp        
    │   └── 3396-minimumOperations.cpp
    └── include/             # 公共头文件（可选）

每个题目单独放在 src 下，命名为：题目号-题目名.cpp

## 🛠️ 构建方法

假设你已经安装好 **CMake (\>=3.21)** 和 **g++/clang++**：

``` bash
# 克隆仓库
git clone https://github.com/kwu130/leetcode-cpp.git
cd leetcode-cpp

# 创建构建目录
mkdir build && cd build

# 生成构建文件
cmake ..

# 编译
make -j8
```

------------------------------------------------------------------------

## 🚀 运行

编译完成后，所有题目会生成对应的可执行文件，例如：

``` bash
./build/1-two_sum
./build/3396-minimumOperations
```

------------------------------------------------------------------------

## ✏️ 添加新题目

1.  在 `src/` 下新建文件，例如`111-minDepth.cpp`并实现算法
3.  不必修改`CMakeLists.txt`，重新执行`cmake`时，会自动引入新题目

------------------------------------------------------------------------

## 📖 参考

-   [LeetCode](https://leetcode.cn/)
-   [CMake 官方文档](https://cmake.org/documentation/)
