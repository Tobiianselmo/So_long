
# So_long

Welcome to the **So_long** project! This project is part of the [42 School](https://www.42.fr/) common core and involves developing a simple 2D game using the MLX42 graphical library.

## About

In **So_long**, you will create a 2D game where a player navigates through a maze, collects items, and reaches an exit. The project uses the MLX42 library for rendering graphics and handling events like keyboard input.

The player controls a character using the keyboard, and the goal is to collect all the items on the map and reach the exit while avoiding traps or obstacles.

## Features

- 2D game built using the MLX42 graphical library.
- Player movement and interaction with the environment.
- Item collection and game objective (reaching the exit).

## Usage

To play the game, run the executable with a valid map file as input.

```bash
./so_long maps/map.ber
```

Controls:
- Use arrow keys to move the player character.
- The objective is to collect all items and reach the exit.

### Example

```bash
./so_long maps/level1.ber
```

## Project Requirements

The project adheres to the following 42 School requirements:
- Use of the MLX42 library for graphical rendering.
- Handling keyboard events for player movement.
- Parsing and validating `.ber` map files.
- Proper error handling for invalid input, map files, or system errors.
