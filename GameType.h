#pragma once
#ifndef _GAMETYPE_H_
#define _GAMETYPE_H_
#include "Game.h"
#include "Board.h"
class GameType
{
};

class HumanvsHuman : public GameType
{
private:
	Board board;
	int turn, key;
public:
	HumanvsHuman();
	~HumanvsHuman();
	void execute(HumanPlayer, HumanPlayer, Game, char**, char**);
	void selection_turn();
};

class HumanvsComputer : public GameType
{
private:
	Board board;
public:
	HumanvsComputer();
	~HumanvsComputer();
	void execute(HumanPlayer, ComputerPlayer, Game, char**, char**);
};

#endif

