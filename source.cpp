
/* This program is the tictactoe game.
Output should look like this:

   0   1   2
0    |   |
-----------
1    |   |
-----------
2    |   |
Row: 1
Col: 1

  0   1   2
0    |   |
-----------
1    | X |
-----------
2    |   |
Row: 1
Col: 2

0   1   2
0    |   |
-----------
1    | X | O
-----------
2    |   |
*/

#include <iostream>
#include "tictactoe.h"

using namespace std;


int main()
{
	tictactoe board;
	int col, row;
	do
	{
		board.DrawBoard();
		cout << "Row: ";
		cin >> row;
		cout << "Col: ";
		cin >> col;

		if (!board.PlaceMove(row, col))
			cout << "Invalid Move" << endl;
	} while (!board.GameOver());

	board.DrawBoard();
	cout << board.Winner() << " wins!" << endl;


	return 0;
}
