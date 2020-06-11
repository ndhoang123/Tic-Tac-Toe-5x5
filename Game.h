#pragma once
#ifndef _GAME_H
#define _GAME_H
#include"Board.h"
class Game
{
private:
	Board bo;
	bool change_status;
	char key;
	int i, j, a, quanX, quanO, set, size, b, sizea, sizeb;
public:
	Game();
	~Game();
	bool isDraw();
	bool isWinner(char **);
	void result(char **);
	void updatingGame(HumanPlayer, HumanPlayer, char**, char **);
	bool isGameover();
	void showBoard(char **);
};
#endif

