# Computers-N-Dragons

When I first learned how to program in C++, I tried making a text-adventure game focused on exploration and exploring rooms in a top down screen. 

In 2023, I brought back the original project that I worked on in 2016, and tried to expand upon it by adding ASCII text with random placement of grass, enemies, and water. 

- ✅ Fully rendered **tile-based world map** in ASCII
- ✅ Player character (`P`) with movement and command interface
- ✅ Hostile entities (`E`) with world logic
- ✅ Multiple terrain types (`.`, `~`, `*`, etc.)
- ✅ Turn-based menu system: `Move`, `Interact`, `Attack`, `Bag`
- ✅ Color-coded UI in terminal
- ✅ Written entirely in modern C++

![Video](https://i.gyazo.com/d2dbfea74ad802be31d68d9eb79d8efb.gif)

# Requirements

- C++ Compiler (g++)
- Terminal that supports ASCII Colors

# How to Run

- Compile all .cpp files in the Tutorial folder.
- g++ *.cpp -o adventure

# Tutorial

- Once the game loads in, type in 2 to Load the Game. 
- Start ends the game currently.
- Once you have options listed out, you can Move, Interact, Attack.
- Move moves your character P.
- Interact tells you what is next to you.
- Attack allows you to try an assortment of attacks based on your hands, feet, head, or an item.


