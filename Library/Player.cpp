#include "Player.h"
#include "Board.h"
//Human Player
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

//Computer Player 
ComputerPlayer::ComputerPlayer(char maker)
{
	this->maker = maker;
}

ComputerPlayer::~ComputerPlayer()
{
}


//find next move with the help of alpha-beta
//want to maximize the evaluation function. It's good for the ComputerPlayer
vector<int> ComputerPlayer::nextMoveAlphaBeta(Board board, HumanPlayer pl, char **current_position, char **position){
	for (int i = 0; i < 2; i++)
	{
		v.push_back(0);
	}
	int m = INT_MIN, x = -1, y = -1;
	
	for (int i = 0; i < 10 ;i++){
		for (int j = 0; j < 10 ; j++){
			if (position[i][j] == ' ' && adjacentPlaced(i, j, position) ){
				int temp = minimaxAlphaBeta (board, pl, current_position, position, 2, true, INT_MIN, INT_MAX, i, j);
				if (m < temp){
					m = temp;
					x = i;
					y = j;
				}
				
			}
		}
	}
	if (x == -1 && y == -1){
		x = 10/2;
		y = 10/2;
	}
	v[0] = x;
	v[1] = y;
	return v;
}




//minimaxAlphaBeta algorithm with alpha-beta to help determine the next move for the ComputerPlayer
//Use evaluation function with depth here.
//higher score is good for ComputerPlayer, lower score is good for player
//isMax = true if the move at (x,y) is of ComputerPlayer
int ComputerPlayer::minimaxAlphaBeta(Board board, HumanPlayer pl, char **current_position, char **position, int depth, bool isMax, int alpha, int beta, int x, int y){
	if(isMax == true){
		board.getValue(current_position, x, y, maker);
		board.assignValuetoSpace(current_position, position);}
	else
	{
		board.getValue(pl, current_position);
		board.assignValuetoSpace(current_position, position);
	}

	if(game.isWinner(position) == true)
	{
		board.getValue(current_position, x, y, ' ');
		board.assignValuetoSpace(current_position, position);
		if(isMax) return INT_MAX;
		else return INT_MIN;
	}
	else if(game.isDraw(board))
	{
		board.getValue(current_position, x, y, ' ');
		board.assignValuetoSpace(current_position, position);
		return 0;
	}

	if (depth == 0){
		int value = 0;
		if (checkVisitedBoard(board, position) == true){
			value = getEvaluation(board, position); // evaluation of board was already stored
		}else{
			value = evaluation(isMax, position); //need to compute evaluation of this new board
			insertToHashMap(board, value, position); //store evaluation of this new board into memory
		}
		board.getValue(current_position, x, y, ' ');
		board.assignValuetoSpace(current_position, position);
		return value;
	}
	
	//save the X positions of available cells into firstCoord, Y positions of available cells into secondCoord
	vector<int> firstCoord;
	vector<int> secondCoord;
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (position[i][j] == ' ' && adjacentPlaced(i, j, position)){
				firstCoord.push_back(i);
				secondCoord.push_back(j);
			}
		}
	}
	
	int len = (int) firstCoord.size();
	if (isMax == true){ // try to minimize because now is player's turn
		int m = INT_MAX;
		for (int i = 0; i < len; i++){
			int temp = minimaxAlphaBeta(board, pl, current_position, position, depth - 1, false, alpha, beta, firstCoord[i], secondCoord[i]);
			if (m > temp){
				m = temp;
			}
			if (beta > m){
				beta = m;
			 }	
			 if (alpha >= beta){
				break;
			 }
		}
		board.getValue(current_position, x, y, ' ');
		board.assignValuetoSpace(current_position, position);
		return m;
	}else {//try to maximize
		int n = INT_MIN;
		for (int i = 0; i < len; i++){
			int temp = minimaxAlphaBeta(board, pl, current_position, position, depth - 1, true, alpha, beta, firstCoord[i], secondCoord[i]);
			if (n < temp){
				n = temp;
			}
			if (alpha < n){
				alpha = n;
			 }
			 if (alpha >= beta){
				break;
			 }
		}
		board.getValue(current_position, x, y, ' ');
		board.assignValuetoSpace(current_position, position);
		return n;
	}
}




int ComputerPlayer::evaluation(bool isMax, char **position){//if isMax is true, ComputerPlayer is about to make the move at (x,y)

	int sum = 0;
	vector<int> ComputerPlayerPattern(6,0);
	vector<int> playerPattern(6,0);
	
	for (int  i = 0 ; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (position[i][j] != ' '){
				
				//count patterns in columns
				char c = position[i][j];
				bool needMax = c == maker;
				int sameSymbol = 1; // count same symbols in columns 
				
				//consider value at i - k later to see if it's blocked or not
				int l = 1;
				while (i+l<= 9){
					if(position[i+l][j] == c)
					{
						sameSymbol++;
						l++;
					}
					else break;
				}

				if (sameSymbol >= 5){
					if (needMax) ComputerPlayerPattern[5]++;
					else playerPattern[5]++;
				}else if (sameSymbol == 4 && (position[i+l-4][j] == ' ' || position[i+l][j] == ' ')){ 				
					if (needMax) ComputerPlayerPattern[4]++;
					else playerPattern[4]++;
				}else if (sameSymbol == 3 && (position[i+l-3][j] == ' ' || position[i+l][j] == ' ')){
					if (needMax) ComputerPlayerPattern[3]++;
					else playerPattern[3]++;
				}else if (sameSymbol == 3 && (position[i+l-3][j] == ' ' && position[i+l][j] == ' ')){
					if (needMax) ComputerPlayerPattern[2]++;
					else playerPattern[2]++;
				}else if (sameSymbol == 2 && position[i+l-2][j] == ' ' && position[i+l][j] == ' '){
					if (needMax) ComputerPlayerPattern[1]++;
					else playerPattern[1]++;
				}
				
				
				//-------------------------------------------------------------------------------
				sameSymbol = 1; // count same symbols in rows
				
				//consider value at i - k later to see if it's blocked or not
				l = 1;
				while (j + l <= 9){
					if(position[i][j+l] == c)
					{
						sameSymbol++;
						l++;
					}
					else break;
				}

				if (sameSymbol >= 5){
					if (needMax) ComputerPlayerPattern[5]++;
					else playerPattern[5]++;
				}else if (sameSymbol == 4 && (position[i][j+l-4] == ' '|| position[i][j+l] == ' ')){ 				
					if (needMax) ComputerPlayerPattern[4]++;
					else playerPattern[4]++;
				}else if (sameSymbol == 3 && (position[i][j+l-3] == ' '|| position[i][j+l] == ' ')){
					if (needMax) ComputerPlayerPattern[3]++;
					else playerPattern[3]++;
				}else if (sameSymbol == 3 && (position[i][j+l-3] == ' '&& position[i][j+l] == ' ')){
					if (needMax) ComputerPlayerPattern[2]++;
					else playerPattern[2]++;
				}else if (sameSymbol == 2 && position[i][j+l-2] == ' '&& position[i][j+l] == ' '){
					if (needMax) ComputerPlayerPattern[1]++;
					else playerPattern[1]++;
				}
				
				//--------------------------------------------------------------
				
				sameSymbol = 1;// count same symbols in main diagnol
				
				//consider value at i - k later to see if it's blocked or not
				l = 1;
				while (i + l <= 9 && j + l <= 9){
					if(position[i+l][j+l] == c)
					{
						sameSymbol++;
						l++;
					}
					else break;
				}

				if (sameSymbol >= 5){
					if (needMax) ComputerPlayerPattern[5]++;
					else playerPattern[5]++;
				}else if (sameSymbol == 4 && (position[i+l-4][j+l-4] == ' '|| position[i+l][j+l] == ' ')){ 				
					if (needMax) ComputerPlayerPattern[4]++;
					else playerPattern[4]++;
				}else if (sameSymbol == 3 && (position[i+l-3][j+l-3] == ' '|| position[i+l][j+l] == ' ')){
					if (needMax) ComputerPlayerPattern[3]++;
					else playerPattern[3]++;
				}else if (sameSymbol == 3 && (position[i+l-3][j+l-3] == ' '&& position[i+l][j+l] == ' ')){
					if (needMax) ComputerPlayerPattern[2]++;
					else playerPattern[2]++;
				}else if (sameSymbol == 2 && position[i+l-2][j+l-2] == ' '&& position[i+l][j+l] == ' '){
					if (needMax) ComputerPlayerPattern[1]++;
					else playerPattern[1]++;
				}
				
				
				
				//-----------------------------------------------------------------------
				
				
				sameSymbol = 1;// count same symbols in reverse diagnols
				
				//consider value at i - k later to see if it's blocked or not
				l = 0;
				while (i + l <= 9 && j - l >= 0){
					if(position[i+l][j-l] == c)
					{
						sameSymbol++;
						l++;
					}
					else break;
				}

				if (sameSymbol >= 5){
					if (needMax) ComputerPlayerPattern[5]++;
					else playerPattern[5]++;
				}else if (sameSymbol == 4 && (position[i+l-4][j-l+4] == ' '|| position[i+l][j-l] == ' ')){ 				
					if (needMax) ComputerPlayerPattern[4]++;
					else playerPattern[4]++;
				}else if (sameSymbol == 3 && (position[i+l-3][j-l+3] == ' '|| position[i+l][j-l] == ' ')){
					if (needMax) ComputerPlayerPattern[3]++;
					else playerPattern[3]++;
				}else if (sameSymbol == 3 && (position[i+l-3][j-l+3] == ' '&& position[i+l][j-l] == ' ')){
					if (needMax) ComputerPlayerPattern[2]++;
					else playerPattern[2]++;
				}else if (sameSymbol == 2 && position[i+l-2][j-l+2] == ' '&& position[i+l][j-l] == ' '){
					if (needMax) ComputerPlayerPattern[1]++;
					else playerPattern[1]++;
				}
				
				
			}	
		}
	}
	if (ComputerPlayerPattern[5] > 0) return INT_MAX;
	if (playerPattern[5] > 0) return INT_MIN;
	int x = 1;
	sum += ComputerPlayerPattern[1];
	sum -= playerPattern[1]*5;
	for (int i = 2 ; i < 5 ; i++){
		//cout <<ComputerPlayerPattern[i] << " : "<<playerPattern[i]<<endl;
		x *= 100;
		sum += ComputerPlayerPattern[i] * x;
		sum -= playerPattern[i] * x * 10;
	}	
	return sum;
}




bool ComputerPlayer::adjacentPlaced(int x, int y, char **position){

	bool value = false;
	if (position[x][y] != ' ') return false;
	vector<vector<int>> adjacent(8, vector<int>(2, -1));
	for(int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if(((i == 1 ||i == 6) && j == 1) || ((i == 3||i == 4) && j == 0)) adjacent[i][j] = 0;
			else if(((i == 2 || i == 3 || i == 7)&& j == 1) || ((i == 5 || i == 6 || i == 7)&& j == 0)) adjacent[i][j] = 1;
		}

	}
	for (auto d:adjacent){

		if (x+d[0] >=0 && y+d[1]>=0 && x+d[0] <= 9 && y + d[1] <= 9){
			value = value || (position[x+d[0]][y+d[1]] != ' ');
		}
	}
	return value;
}




//check if the evaluation function of a particular board is already in the memory or not
bool ComputerPlayer::checkVisitedBoard(Board board, char **position){
	s = board.toString(position);
	if (hashMap.find(s) != hashMap.end()){
		return true;
	}
	return false;
}


//if the evaluation function of a board is already in the memory, just need to take it out.
// this will save time computing the evaluation function of the board.
int ComputerPlayer::getEvaluation(Board board, char **position){
	if (checkVisitedBoard(board, position)){
		return hashMap[board.toString(position)]; 
	}
	return -1;
}


//insert values to hash map

void ComputerPlayer::insertToHashMap(Board board, int eval, char **position){
	s = board.toString(position);
	hashMap[s] = eval;
	return;
}

//Get maker from the computer player
char ComputerPlayer::getMaker()
{
	return this->maker;
}
//Get position from the computer player
tuple<int, int>ComputerPlayer::getMove()
{
	return make_tuple(v[0],v[1]);
}