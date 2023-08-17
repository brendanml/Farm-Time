# FARM TIME!
* Personal top-down, 2D farming game
* Written in C++ with the raylib library

## 1. COMPILE
```
clang++ main.cpp -std=c++11 -lraylib -o main
```
## 2. RUN
```
./main
```

## CHANGELOG AND FEATURES

1. Implemented both grass tile and tree maps using 2D arrays

2. Attempted to implement collision with the trees by using an array of rectangle collision boxes - it would be far to complicated and far too slow
   1. I plan on implementing collision instead by creating a map of walkable tiles that gets updated when objects like trees are added.