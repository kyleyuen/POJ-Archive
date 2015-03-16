#include <iostream>

using namespace std;

bool board[25][25];

void initial();
int solve(int x, int y);
bool exist_garbage();

int main()
{
	int x, y;
	while (cin >> x >> y) {
		if (x == -1 && y == -1) {
			break;
		}
		cout << solve(x, y) << endl;
	}
	return 0;
}

void initial()
{
	for (int i = 1; i <= 24; ++i) {
		for (int j = 1; j <= 24; ++j) {
			board[i][j] = false;
		}
	}
}

int solve(int x, int y)
{
	initial();
	board[x][y] = true;
	while (cin >> x >> y) {
		if (x == 0 && y == 0) {
			break;
		}
		board[x][y] = true;
	}

	int result = 0;
	while (exist_garbage()) {
		int row = 1, column = 1;
		for (int i = row; i <= 24; ++i) {
			for (int j = column; j <= 24; ++j) {
				if (board[i][j]) {
					board[i][j] = false;
					column = j;
				}
			}
		}
		++result;
	}
	return result;
}

bool exist_garbage()
{
	for (int i = 1; i <= 24; ++i) {
		for (int j = 1; j <= 24; ++j) {
			if (board[i][j]) {
				return true;
			}
		}
	}
	return false;
}
