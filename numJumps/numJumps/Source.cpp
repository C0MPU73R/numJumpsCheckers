//Rewritten: 09/17/2019
#include <iostream>
using namespace std;
int main()
{
	char board[8][8];
	int counter = 0;
	int row;
	int col;
	int counter = 0;
	reset(board);
	print(board);
	function1(row, col, board, counter);
	print(board);
	system("pause");
	return 0;
}
void reset(char board[8][8])
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{

			board[i][j] = ' ';

		}
	}
}
int function1(int row, int col, char board[8][8], int& counter)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[row][col] == 'r' && (board[row + 1][col + 1] == 'b' && board[row + 2][col + 2] == ' '))
			{
				board[row + 2][col + 2] = board[row][col];
				board[row][col] = ' ';
				board[row + 1][col + 1] = ' ';
				counter++;
				board[row][col] = board[row + 2][col + 2];
				board[row + 2][col + 2] = ' ';

				return function1(row, col, board, counter);
			}
		}
	}
}
void print(char board[8][8])
{
	cout << "  0   1   2   3   4   5   6   7" << endl;
	cout << "---------------------------------" << endl;
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << "| " << board[i][j] << " ";
		}
		cout << "| ";
		cout << i;
		cout << endl;
		cout << "---------------------------------" << endl;
	}
}