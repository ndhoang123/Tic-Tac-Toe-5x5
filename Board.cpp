#include "Board.h"

int Board::getSize() { return size; }
int Board::getRows() { return rows; }
int Board::getColumns() { return columns; }

void Board::drawBoard(int rows, int columns, int size) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++) {
			Common::gotoXY(rows + 4 * i, columns + 2 * j);
			Common::txtColor(10);
			cout << ".";
		}
	}


	// vẽ viền cho bàn cờ
	for (int i = 0; i <= size * 4 + 1; i++) {
		Common::txtColor(14);
		//Vẽ viền trên
		Common::gotoXY(rows + i - 1, columns - 1);
		cout << char(42);
		//Vẽ viền dưới
		Common::gotoXY(rows + i - 1, columns + size * 2 + 1);
		cout << char(42);
	}

	for (int j = 0; j < size * 2 + 3; j++) {
		//vẽ viền trái
		Common::gotoXY(rows - 1, columns + j - 1);
		cout << char(42);
		//vẽ viền phải
		Common::gotoXY(rows + size * 4 + 1, columns + j - 1);
		cout << char(42);
	}
}
	

