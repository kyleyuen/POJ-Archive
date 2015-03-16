#include <iostream>
#include <vector>

using namespace std;

int solve(int row, int column, int start_x, int start_y);
void dfs(vector< vector<char> >& matrix, vector< vector<bool> >& state, int& perimeter, int x, int y);

int main()
{
	int row, column;
	int start_x, start_y;
	while (cin >> row >> column >> start_x >> start_y) {
		if (row == 0 && column == 0) {
			break;
		}
		cout << solve(row, column, start_x, start_y) << endl;
	}
	return 0;
}

int solve(int row, int column, int start_x, int start_y)
{
	vector< vector<char> > matrix(row + 2, vector<char>(column + 2, '.'));
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			cin >> matrix[i][j];
		}
	}

	int perimeter = 0;
	vector< vector<bool> > state(row + 2, vector<bool>(column + 2, true));
	dfs(matrix, state, perimeter, start_x, start_y);
	return perimeter;
}

void dfs(vector< vector<char> >& matrix, vector< vector<bool> >& state, int& perimeter, int x, int y)
{
    state[x][y] = false;
	int increase = 4;
	if (matrix[x - 1][y] == 'X') {
		--increase;
		if (state[x - 1][y]) {
			dfs(matrix, state, perimeter, x - 1, y);
		}
	}
	if (matrix[x - 1][y + 1] == 'X' && state[x - 1][y + 1]) {
		dfs(matrix, state, perimeter, x - 1, y + 1);
	}
	if (matrix[x][y + 1] == 'X') {
		--increase;
		if (state[x][y + 1]) {
			dfs(matrix, state, perimeter, x, y + 1);
		}
	}
	if (matrix[x + 1][y + 1] == 'X' && state[x + 1][y + 1]) {
		dfs(matrix, state, perimeter, x + 1, y + 1);
	}
	if (matrix[x + 1][y] == 'X') {
		--increase;
		if (state[x + 1][y]) {
			dfs(matrix, state, perimeter, x + 1, y);
		}
	}
	if (matrix[x + 1][y - 1] == 'X' && state[x + 1][y - 1]) {
		dfs(matrix, state, perimeter, x + 1, y - 1);
	}
	if (matrix[x][y - 1] == 'X') {
		--increase;
		if (state[x][y - 1]) {
			dfs(matrix, state, perimeter, x, y - 1);
		}
	}
	if (matrix[x - 1][y - 1] == 'X' && state[x - 1][y - 1]) {
		dfs(matrix, state, perimeter, x - 1, y - 1);
	}

	perimeter += increase;
}
