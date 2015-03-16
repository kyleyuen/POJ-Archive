#include <iostream>
#include <vector>

using namespace std;

int solve(int m, int n);
void visit(vector< vector<char> >& board, vector< vector<bool> >& state, int i, int j, int& result);

int main()
{
	int m, n;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) {
			break;
		}
		cout << solve(m, n) << endl;
	}
	return 0;
}

int solve(int m, int n)
{
	vector< vector<char> > board(m + 2, vector<char>(n + 2, '*'));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}

	int result = 0;
	vector< vector<bool> > state(m + 2, vector<bool>(n + 2, true));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (board[i][j] == '@' && state[i][j]) {
			    ++result;
				visit(board, state, i, j, result);
			}
		}
	}
	return result;
}

void visit(vector< vector<char> >& board, vector< vector<bool> >& state, int i, int j, int& result)
{
	state[i][j] = false;
	if (board[i - 1][j] == '@' && state[i - 1][j]) {
		visit(board, state, i - 1, j, result);
	}
	if (board[i - 1][j + 1] == '@' && state[i - 1][j + 1]) {
		visit(board, state, i - 1, j + 1, result);
	}
	if (board[i][j + 1] == '@' && state[i][j + 1]) {
		visit(board, state, i, j + 1, result);
	}
	if (board[i + 1][j + 1] == '@' && state[i + 1][j + 1]) {
		visit(board, state, i + 1, j + 1, result);
	}
	if (board[i + 1][j] == '@' && state[i + 1][j]) {
		visit(board, state, i + 1, j, result);
	}
	if (board[i + 1][j - 1] == '@' && state[i + 1][j - 1]) {
		visit(board, state, i + 1, j - 1, result);
	}
	if (board[i][j - 1] == '@' && state[i][j - 1]) {
		visit(board, state, i, j - 1, result);
	}
	if (board[i - 1][j - 1] == '@' && state[i - 1][j - 1]) {
		visit(board, state, i - 1, j - 1, result);
	}
}
