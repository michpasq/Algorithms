#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>	//memset()

using namespace std;

// NOTES ABOUT THE CODE:
//
// More efficient possible implementations at:
// https://sites.google.com/site/nqueensolver/home/algorithms/2backtracking-algorithm
//
// To represent board, I could have used a 1d array where the value at each index represent the row.
// For example queens[2] = 3 would mean the queen in column 2 is in row 3. This would work because
// queens should not be in the same column anyway. With this representation, no two values of the 
// 1-d array can be the same (otherwise queens could be in the same column!).
//
// Interesting fact: since each queen is at a [row][col] (whether you represent it with 
// 1d or 2d array), to check for diagonal collisions, all queens' row-col (subtraction) should be different
// and all queens' col-row should be different. If any are same, there is a diagonal collision.
//
// Another interesting fact: suppose two queens at [row1][col1] and [row2][col2].
// tmp = col1 - col2. If tmp == 0 || tmp == row1 - row2 || tmp == row2 - row1, there is a collision
// in column or a diagonal. In other words, if |row1 - row2| == |col1 - col2| there is diagonal collision
// if col1 - col2 == 0 then there is column collision.
//
// The above collision testing strategies rely on you keeping track of where queens are placed
// (i.e. with the 1-d array), so that you can do comparisons instead of scanning for queens
// like current implementation below.

// This is a "pretty print" function
void printBoard(bool** board, int N)
{
	cout << string(2 * N + 1, '*') << '\n';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == true) {
				cout << " 1";
			}
			else {
				cout << " 0";
			}
		}
		cout << '\n';
	}

	cout << string(2 * N + 1, '*') << '\n';

	return;
}

// Note that this function does NOT check that a queen at [row][col]
// is safe in a) its row, b) its column, and c) both diagonals.
// Since nQueens_Util() places one queen per column (recursively,
// so eventually each row in a column will be tried, but one at a time),
// this function does not check the column "col". It checks the row
// to the left of [row][col] and ascending and descending diagonals
// to the left of [row][col].
bool isSafe(bool** board, int N, int row, int col)
{
	// Check the row to the left of [row][col]
	for (int i = 0; i < col; i++) {
		if (board[row][i] == true) {
			return false;
		}
	}

	int i, j;
	// Check the ascending diagonal to the left of [row][col]
	for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == true) {
			return false;
		}
	}

	// Check the descending diagonal to the left of [row][col]
	for (i = row + 1, j = col - 1; i < N && j >= 0; i++, j--) {
		if (board[i][j] == true) {
			return false;
		}
	}
}

// This function has the main logic for recursively finding solutions
// for N Queens, with backtracking
bool nQueens_Util(bool** board, int N, int col, int& numSolutions)
{
	if (col >= N) {
		cout << "PLACED IN ALL COLUMNS\n";
		numSolutions++;
		printBoard(board, N);
		return true;
	}
	else {
		for (int i = 0; i < N; i++) {
			printf("trying [%i][%i]\n", i, col);
			if (isSafe(board, N, i, col)) {
				board[i][col] = true;
				printf("[%i][%i] is safe\n", i, col);
				printf("[%i][%i] == 1 is set\n", i, col);

				cout << "recurse with col == " << (col + 1) << '\n';
				if (nQueens_Util(board, N, col + 1, numSolutions) == true) {
					cout << "recursion on col == " << (col + 1) << " returned true!\n";
					//return true;	// If you return here, algorithm terminates after first solution is found!
				}

				board[i][col] = false;	// Remove this [row][col] from solution for back tracking
				printf("[%i][%i] == 0 is unset\n", i, col);
			}
			printf("[%i][%i] not safe\n", i, col);
		}
		cout << "Finished all bad rows in col == " << col << " , back tracking\n";
		return false;	// Back track
	}
}

// Uses nQueens_Util() for main logic. Contains local variable to pass by
// reference to nQueens_Util() to count solutions.
int nQueens(int N)
{
	int numSolutions = 0;

	bool** board = new bool*[N]();
	for (int i = 0; i < N; i++) {
		board[i] = new bool[N]();
		memset(board[i], 0, N*sizeof(bool));
	}

	// These lines were for when the algorithm returned true
	// on successful recursive call, e.g. it was when
	// the algorithm terminated after finding first solution.
	//if (nQueens_Util(board, N, 0, numSolutions) == true)
	//	printBoard(board, N);
	//else
	//	cout << "No Solution\n";

	// Now the return in nQueens_Util() is commented out, giving the algorithm
	// the chance to consider more (well, all) solutions
	nQueens_Util(board, N, 0, numSolutions);
	printf("\nThere are %i solutions for board with size %i\n", numSolutions, N);

	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}

	return numSolutions;
}

// Driver program:
int main()
{
	int n = 4;
	int numSolutions = 0;
	numSolutions = nQueens(n);
	std::cout << "N = " << n << "\nNumber of solutions = " << numSolutions << '\n';
	return 0;
}
