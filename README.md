# cpp-ttnn-project-template
C++ ttnn project template

# How To Start
chmod +x init_repo.sh

./init_repo.sh

# Some commands to use now

cmake  -DCMAKE_BUILD_TYPE=Debug -B debug

cmake --build debug --config Debug --clean-first

clang-tidy framework/main.cpp -p debug