# Sokoban

Implementation of the clasic Sokoban videogame.

Project for semester 1 of the Epitech Unix System Programing module.

### Description

This project is about reacreating the Sokoban game in a linux terminal using ncurses. It has to manage user input and the map parsing. The real difficulty of this project came from managing all the information, movements and display.

## Getting Started

### Dependencies

- [Linux](https://linux.org/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)
- [LibC](https://www.gnu.org/software/libc/)
- [ncurses](https://linux.die.net/man/3/ncurses)

### Installation

* Download/Clone the repository and enter its directory
* Compile the code typing `make`

## Usage
- **Execution** `./sokoban file`

### Valid files

I provide 2 simple maps to test the program, but you can make your own maps. The maps do not need to be closed. Files must only contain valid characters and spaces.

- **P** This is the player. There must be exactly one.
- **X** This are the boxes. There can not be more boxes than placements.
- **O** This are the placements. Boxes have to be pushed here.
- **#** This is a wall. You can not move things through here.

Example:
```
# ##########
 P        O#
###       ##
  #   X   #
  #    X  ##
  #   X    ### ##
###            O#
#          ######
############
```

## Acknowledgments

* [Epitech](https://www.epitech.eu/)

## Authors
* **Daniel Sanchez** ([GitHub](https://github.com/angsanch) / [LinkedIn](https://www.linkedin.com/in/angeldanielsanchez/))

## License
This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
