# cpp-ttnn-project-template
C++ ttnn project template


# How To Start
You need to have built tt-metal locally: https://github.com/tenstorrent/tt-metal/

Then simply run this commands:

`chmod +x init_repo.sh`

`./init_repo.sh`


# Features

* `clang-format` in precommit hook.
* `clang-tidy` to run manually (for now).
* `.clangd` with c++20 support for the vscode


# Some commands to use now

`cmake  -DCMAKE_BUILD_TYPE=Debug -B debug -GNinja`

`cmake --build debug --config Debug --clean-first`

`clang-tidy sources/examples/sample_app/main.cpp -p debug`

`./debug/sources/examples/sample_app/sample_app`

# Testing

Run `ctest` from your build folder
