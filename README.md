# Rock-Paper-Scissors

This project is a simple console-based Rock-Paper-Scissors game built for practice with programming fundamentals, clean code, and divide-and-conquer design.

> Note: This code currently uses Windows-specific console commands in `GetWinnerScreenColor` and `ResetScreen`, so it is intended to run on Windows only. To make it work on another operating system, change the `system("command")` string in those functions to the equivalent command for your OS command line.

## About

The game lets a human player compete against the computer over a user-defined number of rounds. It demonstrates basic C++ programming skills while keeping the code organized and readable.

## Features

- Choose the number of rounds to play (1 to 10).
- Player vs computer gameplay with random computer choices.
- Per-round results showing player choice, computer choice, and round winner.
- Overall game summary with win counts and final winner.
- Replay prompt after each game.
- Simple console UI with screen reset and color feedback based on the result.
- Clean code structure using enums, structs, and helper functions.

## How to play

1. Run the program.
2. Enter the number of rounds to play (1 to 10).
3. For each round, choose one of the following options:
   - `1` for Rock
   - `2` for Paper
   - `3` for Scissors
4. The computer randomly chooses Rock, Paper, or Scissors.
5. The winner for each round is displayed, and after all rounds the overall game results are shown.
6. After the game ends, choose whether to play again.

## How to run

### Using Visual Studio

1. Open `Rock-Paper-Scissors.sln` in Visual Studio.
2. Build the solution.
3. Run the project.

## Programming topics covered

- C++ input/output (`cin`, `cout`)
- Control flow (`if`, `switch`, loops)
- Enumerations (`enum`)
- Structs for grouping related data
- Functions for modular code
- Random number generation
- Basic game loop logic
- Screen reset and simple console UI feedback

## Code organization

The project uses separate helper functions and data structures to keep logic clean. The code is divided into small units for reading input, generating random choices, deciding the winner, and printing results.
