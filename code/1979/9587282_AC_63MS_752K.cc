#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

int solve(int row, int column);
void dfs(vector< vector<char> >& board, vector< vector<bool> >& state, Point point, int& result);

int main()
{
	int row, column;
	while (cin >> column >> row) {
		if (row == 0 && column == 0) {
			break;
		}
		cout << solve(row, column) << endl;
	}
	return 0;
}

int solve(int row, int column)
{
	vector< vector<char> > board(row + 2, vector<char>(column + 2, '?'));
	Point start;
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			cin >> board[i][j];
			if (board[i][j] == '@') {
				start.x = i;
				start.y = j;
			}
		}
	}

	int result = 0;
	vector< vector<bool> > state(row + 2, vector<bool>(column + 2, true));
	dfs(board, state, start, result);
	return result;
}

void dfs(vector< vector<char> >& board, vector< vector<bool> >& state, Point point, int& result)
{
	++result;
	state[point.x][point.y] = false;

	if (board[point.x - 1][point.y] == '.' && state[point.x - 1][point.y]) {
		--point.x;
		dfs(board, state, point, result);
		++point.x;
	}
	if (board[point.x][point.y + 1] == '.' && state[point.x][point.y + 1]) {
		++point.y;
		dfs(board, state, point, result);
		--point.y;
	}
	if (board[point.x + 1][point.y] == '.' && state[point.x + 1][point.y]) {
		++point.x;
		dfs(board, state, point, result);
		--point.x;
	}
	if (board[point.x][point.y - 1] == '.' && state[point.x][point.y - 1]) {
		--point.y;
		dfs(board, state, point, result);
		++point.y;
	}
}
