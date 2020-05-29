#include <iostream>
#include "Common.h"
using namespace std;
class Board
{
private:
	int rows;
	int columns;
	int size;
public:
	void drawBoard(int rows, int columns, int size);
	int getSize();
	int getRows();
	int getColumns();
	int getLeftDiagonal();
	int getRightDiagonal();
};

