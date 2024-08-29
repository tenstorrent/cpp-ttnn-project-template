# cpp-ttnn-project-template
C++ ttnn project template

# How To Start
chmod +x init_repo.sh

./init_repo.sh

# Some commands to use now

cmake  -DCMAKE_BUILD_TYPE=Debug -B debug -GNinja

cmake --build debug --config Debug --clean-first

clang-tidy sources/examples/sample_app/main.cpp -p debug

# Testing

Run ctest from your build folder