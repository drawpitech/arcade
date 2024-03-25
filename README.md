# Arcade

> [!NOTE]
> This is a 2nd year project at [Epitech](https://epitech.eu/).


## Description

Arcade is a gaming platform: a program that lets the user choose a game to play
and keeps a register of player scores.

To be able to deal with the elements of your gaming plateform at run-time,
the graphics libraries and your games must be implemented as dynamic libraries,
loaded at run-time.

Each GUI available for the program must be used as a shared library that will
be loaded and used dynamically by the main program.


## Compilation

On *nix systems, you can compile the project using the following commands:
(the list of dependencies is abstract, so good luck figuring out)
```sh
cmake -S . -B build
cmake --build build
./build/arcade
```
*All shared objects are built in lib/*

Or if you have `nix`, just use `nix run`.
