# Reverse Polish Notation (RPN) Calculator

Scientific calculator using [reverse polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) with complementary feature to write and execute user-written program easily.

# Prerequisites (Linux)
* C++ compiler (gcc, g++, ...)
* Qt5
* Cmake
* SQLite

To install qt5, go [here](https://www.qt.io/offline-installers) to download zip file and follow instructions on their page. For C++, Cmake and their dependencies, use following command:
```
sudo apt-get install cmake g++
```

# Build the application (Linux)
```
mkdir build && cd build && cmake .. && cd ..
cmake -S . -B build
cmake --build build
```

# How to run (Linux)
The executable file will be in the build directory:
```
build/RPN_Calculator
```

# Application Interface
![image](https://user-images.githubusercontent.com/40765474/111141668-18039f80-8584-11eb-84d6-31bc3c3a496c.png)
