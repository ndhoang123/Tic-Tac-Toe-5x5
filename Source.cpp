#include<iostream>
#include<stdlib.h>
#include"Game.h"
#include"Player.h"
#include"Board.h"
#include"GameType.h"
//#include"Common.h"
using namespace std;

int main()
{
	char key1, key2;
	int turn, gametype;
	Game game;
	HumanvsHuman hvh;
	HumanvsComputer hvc;
	char **position, **current_position;
	position = new char*[10];
	for(int i = 0; i < 10; i++)
	{
		position[i] = new char[10];
	}
	current_position = new char*[10];
	for(int i = 0; i < 10; i++)
	{
		current_position[i] = new char[10];
	}
	//Choosing game type
	cout << "What kind of game type do you wanna choose?" << endl;
	cout << "1: Human vs Human" << endl;
	cout << "2: Human vs Computer" << endl;
	cout << "Your choosing is " << endl;
	cin >> gametype;
	system("CLS");
	//Choosing the mark
	cout << "What kind of marks do you wanna choose?" << endl;
	cout << "1: Your mark is X. Your enemy's mark is O" << endl;
	cout << "2: Your mark is O. Your enemy's mark is X" << endl;
	cout << ">3: Your choosing is default (X)" << endl;
	cout << "Your choosing is: ";
	cin >> turn;
	if(turn == 2)
	{
		key1 = 'O';
		key2 = 'X';
	}
	else
	{
		key1 = 'X';
		key2 = 'O';
	}
	system("CLS");
	if(gametype == 1) {
		HumanPlayer pl1(key1);
		HumanPlayer pl2(key2);
		hvh.selection_turn();
		hvh.execute(pl1, pl2, game, current_position, position);
	}
	else 
	{
		HumanPlayer pl1(key1);
		ComputerPlayer pl2(key2);
		hvc.execute(pl1, pl2, game, current_position, position);
	}

	for(int i = 0; i < 10; i++)
	{
		delete[] position[i];
	}
	delete[] position;
	for(int i = 0; i < 10; i++)
	{
		delete[] current_position[i];
	}
	delete[] current_position;
	system("Pause");
	return 0;
}