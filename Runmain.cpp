#include"Player.h"
#include"Board.h"
int main()
{
	int a, b;
	HumanPlayer pl1;
	Board board;
	pl1.setValue(10, 10,'X');
	/*cout <<"The maker in player 1 is " << pl1.getMaker() << endl;
	tie(a, b) = pl1.getMove();
	cout << a << ", ";
	cout << b << endl;*/
	board.getValue(pl1);
	board.assignValuetoSpace();
	if(board.isOnBoard() == true)
	{
		return 1;
	}
	else
	{
		cout << "You are the winner :v" << endl;
	}
	system("Pause");
	return 0;
}