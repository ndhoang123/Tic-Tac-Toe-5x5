#pragma once
#ifndef _BOARD_H
#define _BOARD_H
#include<iostream>
#include<stdlib.h>
#include "Player.h"
#include "Common.h"

using namespace std;

class Board
{
private:
	char maker;
	char **current_position;
	char **position;
	int rows, columns, counts;
	friend class Game;
public:
	Board();
	~Board();
	bool theBoardIsOver();
	bool isOnBoard(char **, char **);
	void getValue(HumanPlayer, char **);
	void assignValuetoSpace(char**, char**);
	void drawBoard(char **);
	void decreaseCount();
	void showBoard(char **);
	//Board operator=(const Player& pl);
};

#endif

