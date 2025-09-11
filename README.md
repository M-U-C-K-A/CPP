# C++ Learning Projects - 42 School

This repository contains C++ exercises and projects from the 42 School curriculum, covering fundamental to advanced C++ programming concepts across 9 modules (CPP 0-8).

## 📚 Module Overview

| Module | Focus Area | Key Concepts |
|--------|------------|--------------|
| **CPP 0** | Basics | Namespaces, classes, member functions, stdio streams |
| **CPP 1** | Memory allocation, pointers, references | References, pointers, switch statements |
| **CPP 2** | Ad-hoc polymorphism, operator overloading | Fixed-point numbers, operator overloading |
| **CPP 3** | Inheritance | Class inheritance, access specifiers |
| **CPP 4** | Subtype polymorphism, abstract classes | Virtual functions, abstract classes, interfaces |
| **CPP 5** | Exceptions | Exception handling, try/catch blocks |
| **CPP 6** | C++ casts | Static, dynamic, const, reinterpret casts |
| **CPP 7** | C++ templates | Function templates, class templates |
| **CPP 8** | Templated containers, iterators | STL containers, iterators, algorithms |

## 🏗️ Project Structure

```
CPP/
├── CPP 0/          # Basics (ex00-ex02)
├── CPP 1/          # Memory & References (ex00-ex06)  
├── CPP 2/          # Operator Overloading (ex00-ex03)
├── CPP 3/          # Inheritance (ex00-ex03)
├── CPP 4/          # Polymorphism (ex00-ex03)
├── CPP 5/          # Exceptions (ex00-ex03)
├── CPP 6/          # Casts (ex00-ex02)
├── CPP 7/          # Templates (ex00-ex02)
├── CPP 8/          # STL (ex00-ex01)
└── learn/          # Practice files
```

Each module contains multiple exercises (ex00, ex01, etc.) with their own source files and Makefiles.

## 🚀 Getting Started

### Prerequisites
- C++ compiler supporting C++98 standard (g++, clang++)
- Make build system
- Unix-like environment (Linux/macOS)

### Building and Running

Each exercise can be built independently using its Makefile:

```bash
# Navigate to any exercise directory
cd "CPP 7/ex00"

# Build the project
make

# Run the executable
./functions

# Clean build files
make clean

# Complete cleanup
make fclean
```

### Example: Building CPP 7 Exercise 0

```bash
cd "CPP 7/ex00"
make
./functions
```

Output:
```
┌────────────────────────────────────────┐
│ TEST 1 - WITH INTEGERS                 │
└────────────────────────────────────────┘
Before swap: a = 2, b = 3
After swap: a = 3, b = 2
min(a,b)  : 2
max(a,b)  : 3
```

## 📋 Compilation Flags

All projects use strict compilation flags as required by 42 School:
- `-Wall -Wextra -Werror` (All warnings as errors)
- `-std=c++98` (C++98 standard compliance)

## 🎯 Learning Objectives

This curriculum progressively builds C++ expertise through:

1. **Object-Oriented Programming**: Classes, objects, encapsulation
2. **Memory Management**: Stack vs heap, RAII principles
3. **Polymorphism**: Virtual functions, abstract classes
4. **Generic Programming**: Templates and template specialization
5. **STL Usage**: Containers, iterators, algorithms
6. **Exception Handling**: Safe error handling practices
7. **Modern C++ Practices**: Following C++98 standards

## 🔧 Development Notes

- Code follows 42 School coding standards
- Each exercise includes comprehensive test cases
- Proper error handling and edge case coverage
- Memory leak prevention and resource management

## 📖 About 42 School

[42](https://42.fr/) is a tuition-free, peer-to-peer learning programming school. The C++ curriculum is designed to provide a solid foundation in modern C++ development practices.
