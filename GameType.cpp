#include "GameType.h"

//HumanvsHuman mode
HumanvsHuman::HumanvsHuman()
{
	turn = 0;
	key = 0;
}

HumanvsHuman::~HumanvsHuman()
{
}

void HumanvsHuman::selection_turn()
{
	cout << "Pls, choose your turn" << endl;
	cout << "Insert 1 if you wanna play firstly, your enemy wil player the second.";
	cout << " Otherwise, your turn will be the second, and your enemy will play first." << endl;
	cout << "Your value is " << endl;
	cin >> key;
	system("CLS");
}

void HumanvsHuman::execute(HumanPlayer pl1, HumanPlayer pl2, Game game, char **current_position, char **position)
{
	while(1)
	{
		game.showBoard(board, position);
		if(key == 1) game.updatingHumanvsHumanMode(board, pl1, pl2, current_position, position);
		else game.updatingHumanvsHumanMode(board, pl2, pl1, current_position, position);
		if(game.isWinner(position) == true || game.isDraw(board) == true)
		{
			system("CLS");
			game.showBoard(board, position);
			game.result(board, position);
			break;
		}
		else system("CLS");
	}
}


//HumanvsComputer mode
HumanvsComputer::HumanvsComputer()
{
}

HumanvsComputer::~HumanvsComputer()
{
}

void HumanvsComputer::execute(HumanPlayer pl1, ComputerPlayer pl2, Game game, char **current_position, char **position)
{
	while(1)
	{
		game.showBoard(board, position);
		game.updatingHumanvsComputerMode(board, pl1, pl2, current_position, position);
		if(game.isWinner(position) == true || game.isDraw(board) == true)
		{
			system("CLS");
			game.showBoard(board, position);
			game.result(board, position);
			break;
		}
		else system("CLS");
	}

}

