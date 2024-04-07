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
./arcade lib/arcade_ncurses.so
```
*All shared objects are built in lib/*

Or if you have `nix`, just use `nix build`.


## Interface Sharing

We needed to share our graphical and game library interfaces with at least one
other project group. After turn-in, it will therefore be possible to run your
games using their launcher and graphical libraries, and vice-versa.

We shared the **ASS** (Arcade Standard Specification) library.

Our team:
- Clément (*clement.boillot@epitech.eu*)
- Baptiste (*baptiste.girardeau@epitech.eu*)
- Jules (*jules.fradin@epitech.eu*)
Other team:
- Célian (*celian.lombardot@epitech.eu*)
- Jacques (*jacques.ratier@epitech.eu*)
- Théophile (*theophile.combes@epitech.eu*)
