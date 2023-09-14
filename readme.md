# FARM TIME!
* Personal top-down, 2D farming game
* Written in C++ with the raylib library

# Running the Game

## 1. COMPILE IN SRC FOLDER
```bash
make
```
## 2. RUN IN SRC FOLDER
```bash
./game
```

# CHANGELOG AND FEATURES

## 1. Grass and Trees!
- Grass and trees have been added with integer 2D arrays.

## 2. Failed Collision Addition :(
- Using an array of rectangle collision boxes.
   - Far too slow. Would require traversing over the whole array of all collision items at each game update.
> I plan on implementing collision instead by creating a map of walkable tiles that gets updated when objects like trees are added.

## 3. Trees Have Collision Boxes!
* Collision with trees, BONK!

## 4. Chopping trees!
* Changed the tree hitbox map to include the 9 numbered tiles of a tree hitbox.
  * I'm encountering a problem where if trees share a hitbox I'm not sure if I should be deleting it when chopped.

## 5. Trees are choppable!

## 6. Natural Player Movement
* Player movement has been changed to be hold to move (previously spam tap).
* Eliminated the possibility for diagonal moves by consecutively holding buttons.

## 6. Some Codebase Modularity Refactoring
* Class files separated into ".h" and ".cpp" files
* Compile now with ```make```

## IDEAS

* chopping tree thought bubble
* redo tree hitbox map with identifiable tiles 1-9 to know both where tree is on treeMap and what hitboxes to delete
* keep track of if most recent movement has changed -> if it has prioritize that movement
