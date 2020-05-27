#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H
#include<iostream>
#include<string>
#include<tuple>
using namespace std;
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
	HumanPlayer(int, int, char);
	~HumanPlayer();
	char getMaker();
	tuple<int, int> getMove(); //using tuple for returning a couple of values
};
//
//class ComputerPlayer: public Player
//{
//private:
//	char maker;
//	int random_ng, random_do;
//public:
//	ComputerPlayer();
//	~ComputerPlayer();
//	int selectRandomAvailableSpace();
//	char maker(char);
//	int getMove(int, int);
//};

#endif