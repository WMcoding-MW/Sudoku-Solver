/**
 * William Marks
 * August 14, 2020
 * Sudoku solver using a backtracking algorithm.
 */ 
#include <iostream>

const int N = 9;

using namespace std;

void drawSudoku(int board[N][N]);
bool solve(int board[N][N]);
bool nullLocation(int board[N][N], int &i, int &j);
bool currentlyUsed(int board[N][N], int i, int j, int num);

int main(){
	int board[N][N] = {{ 4, 9, 0, 1, 5, 7, 0, 0, 0 }, 
                       { 0, 1, 8, 0, 9, 0, 0, 0, 0 }, 
                       { 7, 5, 0, 2, 8, 4, 1, 0, 6 }, 
                       { 0, 6, 0, 4, 1, 5, 0, 7, 0 }, 
                       { 1, 0, 0, 7, 0, 0, 4, 0, 0 }, 
                       { 0, 0, 0, 9, 0, 8, 0, 6, 1 }, 
                       { 0, 0, 7, 5, 0, 0, 0, 1, 3 }, 
                       { 6, 4, 0, 0, 0, 0, 2, 0, 0 }, 
                       { 5, 0, 1, 0, 7, 0, 0, 8, 0 } };
                       
                       
    cout << "The initial board is: " << endl;
    drawSudoku(board);
    cout << "The 0's represent null values" << endl;
    if(solve(board) == true){
		cout << "The final solution is: " << endl;
		drawSudoku(board);
    }else{
	 	cout << "No solution exists for the given puzzle." << endl;
	 	drawSudoku(board);
	}
					   
}

/*
 * Displayes the sudoku grid to the user
 * Requires: Integer board[N][N]
 */
void drawSudoku(int board[N][N]){
	for(int i = 0; i < N; i++){
	  for(int j = 0; j < N; j++){
		  cout << "[" << board[i][j] << "] ";
		  	  if(j % 3 == 2)
				cout << "| ";
	  }
		  cout << endl;
		 if(i % 3 == 2)
		 cout << "-----------------------------------------" << endl ;
	}
}

/*
 * Main sudoku solver method used recursively to determine if the board is finished
 * being solved or if no soltuon exists
 * Requires: Integer board[N][N]
 * Promises: Boolean value of true if a solution exists; false if it does not
 */
bool solve(int board[N][N]){

int i, j;

if(!nullLocation(board, i, j))
return true;

for(int num = 1; num <= 9; num++){

	if(currentlyUsed(board, i, j, num)){
	
	board[i][j] = num;
	
	if(solve(board))
		return true;
		
	board[i][j] = 0;
	}
}

return false;

}

/*
 * Determines if the location is currently empty
 * Requires: Integer board[N][N], Integer &i, Integer &j
 * Promises: Boolean value of true if it finds an empty space; false if it does not.
 */
bool nullLocation(int board[N][N], int &i, int &j){

for(i = 0; i < N; i++){
	for(j = 0; j < N; j++){
	if(board[i][j] == 0)
	return true;
	}
}
return false;
}

/*
 * Determines if the number is on the board already following the rules of sudoku
 * Requries: Integer board[N][N], Integer i, Integer j, Integer num
 * Promises: Boolean value of true if the number exists; if it does not then false
 */
bool currentlyUsed(int board[N][N], int i, int j, int num){
	
int sX = i - i % 3;
int sY = j - j % 3;
int counter = 0;

	for(int sqX = 0; sqX < 3; sqX++){ //checks the 3x3 square to see if the attempted number is valid
		for(int sqY = 0; sqY < 3; sqY++){
			if(board[sX+sqX][sY+sqY] == num)
				counter++;
		}
	}
	
	for(int row = 0; row < N; row++){ //checks the row to see if the number is valid
		if(board[row][j] == num)
			counter++;
	}
	
	for(int col = 0; col < N; col++){ //checks the column to see if the number is valid
		if(board[i][col] == num)
			counter++;
	}
	
if(counter != 0) //if it exists returns true
	return false;

return true;

}


