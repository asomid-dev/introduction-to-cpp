# Basic C++ Guide for PRO1

This academic documentation is designed to support first-year students in learning C++ programming, following the curriculum of the PRO1 course at UPC-FIB.

The main objective is to provide a solid foundation through structured theoretical explanations, problem-solving, and practical code analysis to avoid the most frequent compilation errors.

## Documentation Structure

The content is divided into two main sections ranging from the fundamentals of the language to two-dimensional data structures and basic algorithms.

* **First Half:**
    * **1. Cpp Basics and Compiling:** Introduction to the environment, variable declaration, and conditional structures.
    * **2. Iterations (Loops):** Flow control through repetition structures and sequential reading.
    * **3. Functions:** Code modularity and parameter passing.
    * **4. Structs:** Grouping variables to create custom data types.
    * **5. Vectors:** Storage and processing of data in one-dimensional sequences.
* **Second Half:**
    * **6. Recursion:** Solving complex problems through self-referencing function calls.
    * **7. Matrices:** Data management in two-dimensional structures (tables).
    * **8. Fundamental Algorithms:** Standard sorting and searching methods (insertion, binary search, etc.).

**Topic structure:**
Each module is formatted as a single file that includes detailed theory and code examples integrated into the explanation. At the bottom of each page, you will find **`final.cpp`**, a complete, executable program that consolidates all the concepts of the lesson.

## Development Environment Setup

To program in C++, you need a **code editor** (like [VSCode](https://code.visualstudio.com/), [Zed](https://zed.dev/), or [Neovim](https://neovim.io/)) or an **IDE** (like [Xcode](https://developer.apple.com/xcode/) for macOS or [Visual Studio 2026](https://visualstudio.microsoft.com/)) and a compiler. Select your operating system to see the installation instructions for the `g++` compiler:

=== "Windows (WSL)"

    It is recommended to use the Windows Subsystem for Linux (WSL) to have a native development environment.

    1. Open a PowerShell terminal as administrator and run:
        ```powershell
        wsl --install -d Ubuntu
        ```
    2. Follow the on-screen instructions to set up a username and password.
    3. Restart the computer if prompted by the system.
    4. Open the new Ubuntu terminal and install the build tools:
        ```bash
        sudo apt update && sudo apt upgrade
        sudo apt install build-essential
        ```

=== "macOS"

    macOS includes build tools via the Xcode Command Line Tools.

    1. Open the Terminal application.
    2. Run the following command to install the necessary components:
        ```bash
        xcode-select --install
        ```
    3. Accept the prompt that appears on screen.

=== "Arch Linux"

    Installation for Arch Linux and its derivatives (like CachyOS or Manjaro).

    1. Open the terminal and run:
        ```bash
        sudo pacman -Syu
        sudo pacman -S base-devel
        ```

=== "Ubuntu / Debian"

    Installation for distributions based on the APT package manager.

    1. Open the terminal and run:
        ```bash
        sudo apt update && sudo apt upgrade
        sudo apt install build-essential
        ```

=== "Fedora" 

    Installation for distributions using the DNF package manager.

    1. Open the terminal and run:
        ```bash
        sudo dnf update
        sudo dnf install gcc-c++
        ```

---

To verify that the installation was successful on any system, run `g++ --version` in the terminal. It should display the current compiler version.

## Credits
* **Author:** Dídac ([@asomid-dev](https://github.com/asomid-dev)).
* **Special thanks:** To Uri ([@ItssUri](https://github.com/ItssUri)) for the preparation, theoretical development, and code implementation of the Matrices section.
