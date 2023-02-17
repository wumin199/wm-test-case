

## build cpp project

```shell
# 需要注意的是-DCMAKE_PREFIX_PATH=/home/xyz/Release/xyz  -> conan包安装路径
# /home/xyz -> /home/wumin199

cmake -B /home/xyz/wm-test-case/build -S /home/xyz/wm-test-case/ -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-linux -DCMAKE_PREFIX_PATH=/home/xyz/Release/xyz -DCMAKE_INSTALL_PREFIX="/opt/xyz/" -DCMAKE_BUILD_TYPE=Release

cmake --build /home/xyz/wm-test-case/build --parallel 10 --config Release
# 或者：
# cd /home/xyz/build
# make -j10


# 其他：
make install
# 格式检查
cmake --build /home/xyz/wm-test-case/build --target clang-format
cmake --build /home/xyz/wm-test-case/build --target cpplint
#格式自动修改
cmake --build /home/xyz/wm-test-case/build --target fix-format

# 或者cd 到build目录执行
make fix-format
make cpplint   # 需要修复cpplint中检测出的问题，修改好后再跑一遍make fix-format
make -j12
make clang-tidy  # 需要修复clang-tidy中检测出的问题，修改结束后建议从头跑一遍ci检查内容
```
