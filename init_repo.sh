# SPDX-FileCopyrightText: (c) 2024 Tenstorrent AI ULC
#
# SPDX-License-Identifier: Apache-2.0


git config --local core.hooksPath .githooks/
chmod +x .githooks/pre-commit
sudo apt install clang-tidy
sudo apt install clang-format

