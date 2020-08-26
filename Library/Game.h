#pragma once
#ifndef _GAME_H
#define _GAME_H
#include<iostream>
class HumanPlayer;
class ComputerPlayer;
class Board;
class Game
{
private:
	bool change_status;
	char key;
	int i, j, a, quanX, quanO, set, size, b, sizea, sizeb;
public:
	Game();
	~Game();
	bool isDraw(Board&);
	bool isWinner(char **);
	void result(Board&, char **);
	void updatingHumanvsHumanMode(Board&, HumanPlayer&, HumanPlayer&, char**, char **);
	void updatingHumanvsComputerMode(Board&, HumanPlayer&, ComputerPlayer&, char**, char**);
	bool isGameover();
	void showBoard(Board&, char **);
};
#endif

