#include "Player.h"

HumanPlayer::HumanPlayer(char maker) 
{
	c_ng = 0;
	c_do = 0;
	this->maker = maker;
}


HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::setValue(int c_ng, int c_do)
{
	this->c_ng = c_ng;
	this->c_do = c_do;
}

char HumanPlayer::getMaker() //This method is used to create to get maker from player
{
	return maker;
}

tuple<int, int> HumanPlayer::getMove() //This method gets move from player in the board
{
	return make_tuple(c_ng, c_do);
}
