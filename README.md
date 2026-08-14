# C++ Basic Examples

This repository contains basic examples of C++ code, demonstrating fundamental concepts and structures in C++ programming.

## Project Structure

- `/vector/` : Contains examples related to the usage of vectors in C++.
- `/map/` : Contains examples related to the usage of maps in C++.
- `/string/` : Contains examples related to the usage of strings in C++.
- `/misc/` : Contains standalone programs, currently an interactive mental arithmetic drill.
- `/scripts/` : Contains helper scripts for working with this repository.

## Getting Started

### Prerequisites

- A working C++ compiler supporting C++17 (GCC, Clang, etc.).
- Basic understanding of C++ syntax.

### Building

Each file is a standalone program and can be compiled on its own:

```sh
g++ -std=c++17 -Wall -Wextra -o basic vector/00.basic.cpp && ./basic
```

To compile every example at once into `build/`:

```sh
./scripts/build_all.sh
```

The script honours `CXX`, `STD` and `OUT` if you need a different compiler,
standard or output directory.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
