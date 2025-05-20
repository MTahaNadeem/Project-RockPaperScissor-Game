# Project-RockPaperScissor-Game
This project aims to create a Rock Paper Scissor game which is based on Command Line Interface (CLI) by using OOP concepts in C++ Programming language. This program/game allows the user to play against the computer.
# Objectives:
The objectives of the project are:
- •	Implement a functional Rock Paper Scissors game with user input and computer-generated moves.
- •	Use OOP C++ programming concepts such as classes, constructors, functions, random number generation, and control structures.
- •	Provide a simple user interface and a scoring system.
# Code Overview:
This code has been created by using several functions to handle different aspects of the program.
- •	Player: Created class and named it  “Player”.
- •	Getter and Setter: Added getter and setters to get and set values of Name, Move, and points.
- •	Game: Created class and named it “Game”. It includes all the functions of this game like Compter Move, Player Move, Result, Displaying result etc.
- •	CompMove: This generates a random move for the computer using the rand() function.
- •	PlayerMove: This takes input from the user, ensuring the valid choice and handles input.
- •	Result: This function determines the outcome of each round based on user and computer moves.
- •	Result: This function displays the result of each round and update the player score accordingly.
- •	Play: Manages the flow of the game including player inputs, result display, and the option to play again. 
- •	main: This main function handles all the program/game flow including all the above classes, functions and loop.

# Key Features:
- •	Random Number Generation: The rand() function is used to generate a random number for the computer's move. The srand(time(0)) function used for the random number generator with the current time to ensure a different sequence of random numbers in each run.
- •	User Input Validation: The PlayerMove function ensures that the user's input is valid (Rock, Paper, or Scissors). It uses a while loop for continuous input until a valid choice is made.
- •	Game Loop: The do-while loop in the main function allows the user to play multiple rounds. The loop continues until the user decides not to play again.
- •	Result Calculation: The game logic determines the winner of each round based on standard Rock, Paper, Scissors rules. 
- •	Final Score Display: When the player decides to stop playing, the program displays the player's final score.
