#include "tictactoe.h"
#include <iostream>

using namespace std;

//should initialize whose turn it is and the moves array with empty space
  tictactoe::tictactoe()
{
this -> xturn = true;
    // Nested For Loop
    int i, j;
    int size = 3;

    for(i = 0; i < size; i++) {

        for(j = 0; j < size; j++) {

            this -> moves[i][j] = ' ';

        }

    }
}

  //should place an X or O, based on whose turn it is, at location x,y in the moves array	
	// make sure the move is correct meaning it is in the board range and also the place is not already occupied	
	// update the turn : If it was X turn, now it is O turn	
bool tictactoe::PlaceMove(int x, int y)
{
    if ((x < 3 && y < 3) && (moves[x][y] == ' ')) {

        if(this -> xturn == true) {

            this -> moves[x][y] = 'X';

            this -> xturn = false;

            return true;

        } else {

            this -> moves[x][y] = 'O';

            this -> xturn = true;

            return true;

        }

    } else {

        return false;

    }

}

/*draws the board using the moves 2d array. At first it should look like this	 	
	      0   1   2	
		0    |   |	
		---------- -	
		1    |   |	
		---------- -	
		2    |   |	
		*/	
void tictactoe::DrawBoard()
{
	cout << "  0  1  2" << endl;
 for (int row = 0; row < 3; row++){
      cout<<row;
      cout<<" ";
  for (int col = 0; col < 3; col++){
   if (col != 2){
    cout << moves[row][col] << " | ";  
   }
   else{
    cout << moves[row][col] << endl;
   }
  }
  cout << endl;
 }

}

//should return true if there are 3 X's or 3 O's in a row or in diagonal ; also return true if the board is full
bool tictactoe::GameOver()
{
	bool well = false;
	int countFull = 0;

	for(int i = 0; i < 3; i++) {
		if(moves[i][0] != ' ' && (moves[i][0] == moves[i][1] && moves[i][0] == moves[i][2])) {
			well = true;
		}
		else if(moves[0][i] != ' ' && (moves[0][i] == moves[1][i] && moves[0][i] == moves[2][i])) {
			well = true;
		}

		for(int j = 0; j < 3; j++) {
			if(moves[i][j] != ' ') {
				countFull += 1;
			}
		}
	}

	if(moves[0][0] != ' ' && (moves[0][0] == moves[1][1] && moves[0][0] == moves[2][2])) {
		well = true;
	}
	else if(moves[2][0] != ' ' && (moves[2][0] == moves[1][1] && moves[2][0] == moves[0][2])) {
		well = true;
	}
	else if(countFull == 9) {
		well = true;
	}

	return well;

} 

//should return X or O ; the winner is usually the one who made the last move. If no body won, and the board is full, return the last person who made a move	
char tictactoe::Winner(){
  if (this-> xturn == true){
    return 'O';
  }
  else{
    return 'X';
  }
  }
