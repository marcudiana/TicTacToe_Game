#include "std_lib_facilities.h"

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard()
{
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "-----------\n";
	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "-----------\n";
	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void placeMarker(int slot) 
{
	int row = slot / 3; 
	int col;
	
	if (slot % 3 == 0) 
	{
		row = row - 1;
		col = 2;
	}
	else 
	{
		col = (slot % 3) - 1;
	}

	board[row][col] = currentMarker;
}

void swapPlayerAndMarker()
{
	if (currentMarker == 'x')
	{
		currentMarker = '0';
	}
	else
	{
		currentMarker = 'x';
	}
	if (currentPlayer == 1)
	{
		currentPlayer = 2;
	}
	else
	{
		currentPlayer = 1;
	}
}

int winner() 
{
	for (int i = 0; i < 3; i++) 
	{

		// check rows
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
		{
			return currentPlayer;
		}

		// check columns
		else if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
		{
			return currentPlayer;
		}

		// check diagonals
		else if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
		{
			return currentPlayer;
		}
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			return currentPlayer;
		}
	}

	return 0;
}

void playGame(int& slot, int& playerWon) 
{
	for (int i = 0; i < 9; i++)
	{
		cout << "It's player " << currentPlayer << " 's turn. Choose your slot : ";
		cin >> slot;
		placeMarker(slot);
		playerWon = winner();
		swapPlayerAndMarker();
		drawBoard();

		if (playerWon == 1)
		{
			cout << "Player 1 won ! Congrats !";
			break;
		}
		else if (playerWon == 2)
		{
			cout << "Player 2 won ! Congrats !";
			break;
		}
	}
}

void initGame()
{
	char markerP1;
	int slot;
	int playerWon;

	cout << "Player 1, choose your marker : ";
	cin >> markerP1;

	currentPlayer = 1;
	currentMarker = markerP1;

	playGame(slot, playerWon);
}


int main() 
{
	cout << " Let's play tic tac toe :)\n" << endl;
	drawBoard();
	initGame();
}

