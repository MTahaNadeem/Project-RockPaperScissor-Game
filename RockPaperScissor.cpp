#include <iostream>
#include <string>
#include <ctime>  // used for random num generation
#include <stdlib.h> // used for random num generation
#include <fstream>
using namespace std;

class Player
{
private:
	string name;
	char move;
	int points;
public:
	Player(string n, int pts = 0)
	{
		name = n;
		points = pts;
	}
	string getName()
	{
		return name;
	}
	void setMove(char m)
	{
		move = m;
	}
	char getMove()
	{
		return move;
	}
	void addPoint()
	{
		points++;
	}
	int getPoints()
	{
		return points;
	}
};

class Game
{
public:
	char CompMove()
	{
		srand(time(0)); // to generate random num in every move
		int move = rand() % 3; // % 3 for generate only 3 random num (0,1,2)
		if (move == 0)
		{
			return 'p';
		}
		else if (move == 1)
		{
			return 's';
		}
		else
		{
			return 'r';
		}
	}

	char PlayerMove() //Player Move to make its decision
	{
		char move;
		cout << "\t\t\bEnter choice from one of these\n\n" << endl;
		cout << "\t\t\ts for Scissor\n\n\t\t\tr for Rock\n\n\t\t\tp for Paper\n\n" << endl;
		while (1)
		{
			cin >> move;
			if (move == 'p' || move == 'r' || move == 's')
			{
				break;
			}
			else
			{
				cout << "\t\tInvalid Move Please Try Again." << endl;
			}
		}
		return move;
	}

	int Result(char playerMove, char computerMove) //logic to declare winner according to rules of the game
	{
		// In this function the (0 used for draw), (1 used for player win), (-1 used for comp win)
		if (playerMove == computerMove)
		{
			return 0;
		}
		if (playerMove == 's' && computerMove == 'p')
		{
			return 1;
		}
		if (playerMove == 's' && computerMove == 'r')
		{
			return -1;
		}
		if (playerMove == 'p' && computerMove == 'r')
		{
			return 1;
		}
		if (playerMove == 'p' && computerMove == 's')
		{
			return -1;
		}
		if (playerMove == 'r' && computerMove == 'p')
		{
			return -1;
		}
		if (playerMove == 'r' && computerMove == 's')
		{
			return 1;
		}
		return 0;
	}

	void dispResult(Player& player, char computerMove, int result) //logic to show/print winner
	{
		cout << "\t\t" << player.getName() << " 's Move: " << player.getMove() << endl;
		cout << endl;
		cout << "\t\tComputer's Move: " << computerMove << endl;
		if (result == 0)
		{
			cout << "\n\t\tGame Draw!\n";
		}
		else if (result == 1)
		{
			cout << "\n\t\tCongratulations " << player.getName() << " won!\n";
			player.addPoint();
		}
		else
		{
			cout << "\n\t\tOh Computer won!\n";
		}
		cout << endl;
	}

	void play()
	{
		cout << "\t\b\b---------------Rock Paper Scissor---------------\n\n" << endl;
		string playerName;
		cout << "\tEnter your Name: ";
		cin >> playerName;
		Player PLY(playerName);
		int playAgain;
		do
		{
			PLY.setMove(PlayerMove());
			char computerMove = CompMove();

			int result = Result(PLY.getMove(), computerMove);

			dispResult(PLY, computerMove, result);

			cout << "Do you want to play again? (1 for yes, 0 for no): ";
			cin >> playAgain;
			cout << endl;

		} while (playAgain == 1);
		cout << "\t\t'''GameOver'''" << endl << endl;
		cout << "Thanks for playing " << PLY.getName() << "'s final score : " << PLY.getPoints() << " points." << endl;

		ofstream file("score.txt");
		file << PLY.getName() << ": " << PLY.getPoints() << " points." << endl;
		file.close();
	}
};

int main() //main function 
{
	Game game;
	game.play();
	return 0;
}