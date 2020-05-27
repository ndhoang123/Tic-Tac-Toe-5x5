#include "Player.h"


HumanPlayer::HumanPlayer(int c_n, int c_d, char makerr) 
{
	this->c_ng = c_n;
	this->c_do = c_d;
	this->maker = makerr;
}


HumanPlayer::~HumanPlayer()
{
}

char HumanPlayer::getMaker() //This method is used to create to get maker from player
{
	return maker;
}

tuple<int, int> HumanPlayer::getMove() //This method gets move from player in the board
{
	return make_tuple(c_ng, c_do);
}
