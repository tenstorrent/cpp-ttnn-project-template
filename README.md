# cpp-ttnn-project-template
C++ ttnn project template


# How To Start
You need to have built tt-metal locally: https://github.com/tenstorrent/tt-metal/

Then simply run this commands:

`chmod +x init_repo.sh`

`./init_repo.sh`

# VSCode setup

* Install CMake plugin.
* Install clang plugin.
* Default launch json expects gdb-14.2

# Features

* `clang-format` in precommit hook.
* `clang-tidy` to run manually (for now).



# Some commands to use now

Use CMake plugin to setup and debug project and tests.

`clang-tidy sources/examples/sample_app/main.cpp -p debug`

`./debug/sources/examples/sample_app/sample_app`

# Testing

Run `ctest` from your build folder
