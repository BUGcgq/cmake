# cmake
1.使用 cd 命令进入你的项目目录
2.创建构建目录并进入：创建一个用于构建的目录，通常命名为 "build"，以保持源代码目录干净。在构建目录中运行 CMake 命令。
mkdir build
cd build
3.运行 CMake：
cmake ..
4.编译项目：运行 make 命令来编译项目。这将根据 CMakeLists.txt 文件中的配置生成可执行文件、动态库和静态库。
make
5.清除编译产物：如果需要清除编译产物，可以执行 make clean 命令。该命令会删除生成的中间文件和目标文件，但保留 CMake 生成的构建系统文件。
make clean
6.删除 build 目录下的所有文件和子目录
rm -rf build or rm -rf ./*