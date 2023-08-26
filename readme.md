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

# CHANGELOG AND FEATURES

## 1. Implemented both grass tile and tree maps using 2D arrays

## 2. Attempted to implement collision with the trees by using an array of rectangle collision boxes - it would be far too complicated and far too slow
   1. I plan on implementing collision instead by creating a map of walkable tiles that gets updated when objects like trees are added.

## 3. Successfully Added Collision for Trees
* Collision with trees BONK

## 4. chopping trees
* changed the tree hitbox map to include the 9 numbered tiles of a tree hitbox
  * encountering problem where if trees share a hitbox: I'm not sure if I should be deleting the hitbox when chopping

## 5. Trees are choppable!

### Natural player movement
* Player movement has been changed to be hold to move (previously tap).
* eliminated the possibility for diagonal moves by consecutively holding buttons.

## IDEAS

* chopping tree thought bubble
* redo tree hitbox map with identifiable tiles 1-9 to know both where tree is on treeMap and what hitboxes to delete
* keep track of if most recent movement has changed -> if it has prioritize that movement