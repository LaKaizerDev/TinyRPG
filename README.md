# TinyRPG

A very basic, beginner-friendly C++ learning project: a simple turn-based RPG battle simulator that runs in the terminal.

## Project Scope

TinyRPG is a small project built to practise fundamental C++ concepts through a hands-on game. The goal is to learn by building something functional rather than creating a fully featured RPG.

### Current Features
- Character creation using classes and constructors
- Encapsulation using private data members and public member functions
- Character stats, including health and attack damage
- Turn-based combat between a Knight and a Dark Mage
- Damage handling and character defeat detection
- Basic terminal output

### Learning Goals
- Classes and objects
- Constructors and member initializer lists
- Public and private access control
- Member functions and `const`
- References and scope resolution
- Header and source file separation (`.h` and `.cpp`)
- Basic control flow and loops
- Compiling and linking multiple C++ source files
- Git and GitHub basics

## Tech Stack
- **Language:** C++17
- **Interface:** Terminal / Command Line
- **Compiler:** GCC (MinGW-w64)

## Project Structure

```text
TinyRPG/
├── main.cpp
├── Character.h
├── Character.cpp
└── README.md
```

## Building and Running

Compile the project using GCC:

```bash
g++ -std=c++17 main.cpp Character.cpp -o main.exe
```

Run the executable on Windows:

```powershell
.\main.exe
```

## Project Status

This is a work in progress and a very basic learning project. Features are being added gradually as I learn C++.

The focus is on understanding the fundamentals, writing the code myself, and improving through practice rather than building a complete game.

