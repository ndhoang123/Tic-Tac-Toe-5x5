#include "Game.h"


Game::Game(void)
{
	quanX = quanO = 0;
	key = 'X';
	i = j = a = b = 0;
	set = 1;
	size = 9;
	change_status = true;
}


Game::~Game(void)
{
}

bool Game::isWinner(char **position)
{
	for (i = 0; i < size+1; i++) //check the row condition
	{
		quanX = quanO = 0;
		for (j = 0; j < size; j++)
		{
			if(position[i][j] == 'X' && position[i][j+1] == 'X') 
			{
				quanX++;
				if(quanX == 4)
				{
					return true;
				}
			}

			else if(position[i][j] == 'O' && position[i][j+1] == 'O') 
			{
				quanO++;
				if(quanO == 4)
				{
					key = 'O';
					return true;
				}
			}
			else quanX = quanO = 0;
		}

	}

	for (j = 0; j < size+1; j++) //check the column condition
	{
		quanX = quanO = 0;
		for (i = 0; i < size; i++)
		{
			if(position[i][j] == 'X' && position[i+1][j] == 'X') 
			{
				quanX++;
				if(quanX == 4)
				{
					return true;
				}
			}

			else if(position[i][j] == 'O' && position[i+1][j] == 'O') 
			{
				quanO++;
				if(quanO == 4)
				{
					key = 'O';
					return true;
				}
			}
			else quanX = quanO = 0;
		}
	}

	for(i = 0; i < 6; i++) // Check the clockwise diagonal condition (from the top to bottom)
	{
		sizea = 5;
		for(j = 0; j < 6; j++)
		{
			for(a = 0; a < sizea; a++)
			{
				if(position[i+a][j+a] == 'X' && position[i+a+1][j+a+1] == 'X' &&
					position[i+a+2][j+a+2] == 'X' && position[i+a+3][j+a+3] == 'X' &&
					position[i+a+4][j+a+4] == 'X')
				{
					return true;
				}

				else if(position[i+a][j+a] == 'O' && position[i+a+1][j+a+1] == 'O' &&
					position[i+a+2][j+a+2] == 'O' && position[i+a+3][j+a+3] == 'O' &&
					position[i+a+4][j+a+4] == 'O')
				{
					key = 'O';
					return true;
				}
			}
			sizea--;
		}
	}
	
	for(i = size; i < 3; i--) // check the clockwise diagonal condition (from the bottom to the top)
	{
		for(j = size; j < 3; j--)
		{
			for(a = 0; a < 2; a++)
			{
				if(i == 4|| j == 4)
				{
					if(position[i-a][j-a] == 'X' && position[i-a-1][j-a-1] == 'X' &&
						position[i-a-2][j-a-2] == 'X' && position[i-a-3][j-a-3] == 'X' &&
						position[i-a-4][j-a-4] == 'X')
					{
						return true;
					}
					else if(position[i-a][j-a] == 'O' && position[i-a-1][j-a-1] == 'O' &&
						position[i-a-2][j-a-2] == 'O' && position[i-a-3][j-a-3] == 'O' &&
						position[i-a-4][j-a-4] == 'O')
					{
						key = 'O';
						return true;
					}
					break;
				}
				else
				{
					if(position[i-a][j-a] == 'X' && position[i-a-1][j-a-1] == 'X' &&
						position[i-a-2][j-a-2] == 'X' && position[i-a-3][j-a-3] == 'X' &&
						position[i-a-4][j-a-4] == 'X')
					{
						return true;
					}
					else if(position[i-a][j-a] == 'O' && position[i-a-1][j-a-1] == 'O' &&
						position[i-a-2][j-a-2] == 'O' && position[i-a-3][j-a-3] == 'O' &&
						position[i-a-4][j-a-4] == 'O')
					{
						key = 'O';
						return true;
					}
				}
			}
		}
	}


	for(i = 0; i < 6; i++) //Check the counterclockwise diagonal condition (from the top to bottom)
	{
		sizea = 5;
		for(j = 9; j > 4; j--)
		{
			for(a = 0; a < sizea; a++)
			{
				if(position[i+a][j-a] == 'X' && position[i+a+1][j-a-1] == 'X' &&
					position[i+a+2][j-a-2] == 'X' && position[i+a+3][j-a-3] == 'X' &&
					position[i+a+4][j-a-4] == 'X')
				{
					return true;
				}

				else if(position[i+a][j-a] == 'O' && position[i+a+1][j+a-1] == 'O' &&
					position[i+a+2][j-a-2] == 'O' && position[i+a+3][j+a-3] == 'O' &&
					position[i+a+4][j-a-4] == 'O')
				{
					key = 'O';
					return true;
				}
			}
			sizea--;
		}
	}

	for(i = 9; i > 3; i--) //Check the counterclockwise diagonal condition (from the top to bottom)
	{
		for(j = 0; j < 5; j++)
		{
			for(a = 0; a < 2; a++)
			{
				if(i == 4 || j == 4)
				{
					if(position[i-a][j+a] == 'X' && position[i-a-1][j+a+1] == 'X' &&
						position[i-a-2][j+a+2] == 'X' && position[i-a-3][j+a+3] == 'X' &&
						position[i-a-4][j+a+4] == 'X')
					{
						return true;
					}

					else if(position[i-a][j+a] == 'O' && position[i-a-1][j+a+1] == 'O' &&
						position[i-a-2][j+a+2] == 'O' && position[i-a-3][j+a+3] == 'O' &&
						position[i-a-4][j+a+4] == 'O')
					{
						key = 'O';
						return true;
					}
					break;
				}

				else
				{
					if(position[i-a][j+a] == 'X' && position[i-a-1][j+a+1] == 'X' &&
						position[i-a-2][j+a+2] == 'X' && position[i-a-3][j+a+3] == 'X' &&
						position[i-a-4][j+a+4] == 'X')
					{
						return true;
					}

					else if(position[i-a][j+a] == 'O' && position[i-a-1][j+a+1] == 'O' &&
						position[i-a-2][j+a+2] == 'O' && position[i-a-3][j+a+3] == 'O' &&
						position[i-a-4][j+a+4] == 'O')
					{
						key = 'O';
						return true;
					}
				}
			}
		}
	}

	return false;
}

void Game::updatingGame(HumanPlayer pl1, HumanPlayer pl2, char **current_position, char **position)
{
	if (change_status == false)
	{
		cout << "Your last value is the same. Pls, re-insert your value again!" << endl;
	}
	cout << "Player " << set << " turn: ";
	cin >> bo.columns >> bo.rows;
	switch (set) //This case is indicated to "human vs human" case
		{
		case 1:
			pl1.setValue(bo.columns, bo.rows); // First, the player sets column, row 
			bo.getValue(pl1, current_position); // Second, get the player's last value
			if(bo.isOnBoard(current_position, position) == false) 
			{
				bo.assignValuetoSpace(current_position, position); // Third, assign the value
				set = 2; // Check condition, if the value is on the board, the player has to re-insert the value again!. 
												//	Otherwise, change the status
				bo.decreaseCount();
				change_status = true;
			}
			else change_status = false;
			break;
		case 2:
			pl2.setValue(bo.columns, bo.rows);
			bo.getValue(pl2, current_position);
			if(bo.isOnBoard(current_position, position) == false)
			{
				bo.assignValuetoSpace(current_position, position);
				set = 1;
				bo.decreaseCount();
				change_status = true;
			}
			else change_status = false;
			break;
		}
}

bool Game::isDraw()
{
	if(bo.theBoardIsOver() == true) return true;
	else return false;
}

void Game::result(char **position)
{
	if(isDraw() == true) cout << "Unfortunely, the game is draw!" << endl;
	else if(isWinner(position) == true) cout << "Player " << key << " is winner in this game" << endl;
	else cout << "Have some problems from the program. Pls, feedback to the developer!" << endl;
}

void Game::showBoard(char **position)
{
	if(bo.counts == 100) 
	{
		bo.drawBoard(position);
		bo.showBoard(position);
	}
	else bo.showBoard(position);
}

