# Bloxorz

## Project Description

- A 3D game implemented in C++ using OpenGL 3.0 . It is similar to : https://www.miniclip.com/games/bloxorz/en/

## Compile and Run

- Compile using 'make' command
- Run using './a.out' command

## Game Description

- Take block to target postion defined by a hole. Stand vertically on hole to complete stage.
- You can't stand vertically on orange tiles.
- Light green tiles are normal bridge switches. Normal bridges can be opened by placing block on the switches.
- Dark green tiles are heavy bridge switches. Heavy bridges can be opened by placing block VERTICALLY on the switches.

## Features 

- There are 3 different levels of game in increasing order of difficulty.
- Sound is enabled. You can feel what is happening with sound.
- The game can easily expand for multiple levels. Just need to add more data describing levels. Levels can be changed by changing 'level' variable in main.cpp file.
- Smooth Animated movements of block and camera.
- Map of world at bottom-left corner.
- Dynamic Stage initialization by reading from a data file.
- Smooth movement of block. (Animated movement).
- Implemented normal bridge and heavy bridge(can be open only by verticle position) and fragile tiles.
- Implemented multiple camera views.

## Controls

- Keyboard controls: (Keys      :     Behaviour)
    - 'a'       :     Block Moves Left
    - 's'       :     Block Moves Downward
    - 'd'       :     Block moves right
    - 'w'       :     Block moves up
    - 't'       :     For top view
    - 'y'       :     For Tower view
    - 'h'       :     Helicopter View
    - 'f'       :     Follow Cam view
    - 'b'       :     Block view








