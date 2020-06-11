#include "Board.h"


Board::Board()
{
	rows = 0;
	columns = 0;
	maker = 0;
	counts = 100;
	
}


Board::~Board()
{
}

void Board::decreaseCount()
{
	counts--;
}

bool Board::theBoardIsOver()
{
	if(counts == 0) return true;
	else return false;
}


void Board::getValue(HumanPlayer pl1, char **current_position)
{
	tie(this->rows, this->columns) = pl1.getMove();
	//this->rows = pl1.getMove();
	this->maker = pl1.getMaker();
	current_position[rows][columns] = maker;
}

void Board::assignValuetoSpace(char **current_position, char **position)
{
	position[rows][columns] = current_position[rows][columns];
}

bool Board::isOnBoard(char **current_position, char **position)
{
	if((current_position[rows][columns] == 'X' && position[rows][columns] == 'O') || 
		(current_position[rows][columns] == 'O' && position[rows][columns] == 'X') || 
		(current_position[rows][columns] == 'X' && position[rows][columns] == 'X') ||
		(current_position[rows][columns] == 'O' && position[rows][columns] == 'O'))
	{
		return true;
	}
	else return false;

}

void Board::drawBoard(char **position)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 ; j++)
		{
			position[i][j] = '  ';
		}
	}

}

void Board::showBoard(char **position)
{
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10 ; j++)
		{
			cout << position[i][j] << '|';
		}
		cout << endl << "====================" << endl;
	}
}

