#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H
#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include<unordered_map>
#include"Game.h"
using namespace std;
class Board;

class Player
{
public:
	char getMaker();
	int getMove();
};

class HumanPlayer: public Player
{
private:
	char maker;
	int c_ng, c_do;
public:
	HumanPlayer(char);
	~HumanPlayer();
	void setValue(int, int);
	char getMaker();
	tuple<int, int> getMove(); //using tuple for returning a couple of values
	/*int getMove_ng();
	int getMove_do();*/
};

class ComputerPlayer: public Player
{
private:
	string s;
	Game game;
	char maker;
	vector<int> v;
	unordered_map<string, int> hashMap;
public:
	ComputerPlayer(char);
	~ComputerPlayer();
	vector<int> nextMoveAlphaBeta(Board, HumanPlayer, char**, char**);
	int minimaxAlphaBeta(Board, HumanPlayer, char**, char**, int, bool, int, int, int, int);
	int evaluation(bool, char**);
	bool adjacentPlaced(int, int, char**);
	bool checkVisitedBoard(Board, char**);
	int getEvaluation(Board, char**);
	void insertToHashMap(Board, int, char**);
	tuple<int, int> getMove();
	char getMaker();
};

#endif