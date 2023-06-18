# 2048 Game
This is a console-based implementation of the popular game "2048" written in C++. The game follows the same rules as the original, where the player combines tiles with the same number to achieve the highest score possible. The goal is to reach the tile with the number 2048.

How to Play
Use the arrow keys (up, down, left, right) to move the tiles on the 4x4 game board.
Tiles with the same number will merge when they collide, creating a new tile with double the value.
After each move, a new tile with a value of 2 will randomly appear on the board.
The game ends when there are no more valid moves available or when the player reaches the 2048 tile.
Technologies Used
The implementation of the game utilizes the following technologies:

C++: The game logic and user interface are written in C++, providing the core functionality and interaction.
Standard Library: The iostream, cstdlib, ctime, iomanip, fstream, and windows.h libraries are used for input/output, random number generation, time-based seed, formatting, file handling, and console manipulation, respectively.
Getting Started
To run the game on your local machine, follow these steps:

Install a C++ compiler (e.g., g++) if you don't have one already.
Download the source code files from the repository.
Open a terminal or command prompt and navigate to the directory containing the source code files.
Compile the code using the C++ compiler. For example, using g++: g++ 2048.cpp -o 2048.
Run the compiled executable. For example, on Windows: 2048.exe.
Gameplay Controls
Arrow Up: Move tiles upwards.
Arrow Down: Move tiles downwards.
Arrow Left: Move tiles to the left.
Arrow Right: Move tiles to the right.
Esc: Exit the game.
Additional Features
Maximum Score Tracking: The game keeps track of the maximum score achieved, which is saved in a file named "max_score.txt".
Game Over: When the game ends, the "GAME OVER" message is displayed, indicating that no more valid moves are available.
Feel free to enjoy playing the 2048 game and challenge yourself to achieve the highest score!
