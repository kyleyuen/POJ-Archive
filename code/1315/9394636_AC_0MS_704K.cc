#include <iostream>

using namespace std;

char board[5][5];

int solve(int n);
void initial();
bool conflict(int i, int j, int n);
void visit(int i, int j, int n, int current, int& result);

int main()
{
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << solve(n) << endl;
	}
	return 0;
}

int solve(int n)
{
	initial();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}

	int result = 0;
	visit(1, 1, n, 0, result);
	return result;
}

void initial()
{
	for (int i = 1; i <= 4; ++i) {
		for (int j = 1; j <= 4; ++j) {
			board[i][j] = 0;
		}
	}
}

void visit(int i, int j, int n, int current, int& result)
{
	if (j > n) {
		++i;
		j = 1;
	}
	if (i > n) {
		if (result < current) {
			result = current;
		}
		return;
	}

	if (board[i][j] == '.' && !conflict(i, j, n)) {
		board[i][j] = 'A';
		visit(i, j + 1, n, current + 1, result);
		board[i][j] = '.';
	}
	visit(i, j + 1, n, current, result);
}

bool conflict(int i, int j, int n)
{
	for (int k = j - 1; k > 0 && board[i][k] != 'X'; --k) {
		if (board[i][k] == 'A') {
			return true;
		}
	}
	for (int k = j + 1; k <= n && board[i][k] != 'X'; ++k) {
		if (board[i][k] == 'A') {
			return true;
		}
	}
	for (int k = i - 1; k > 0 && board[k][j] != 'X'; --k) {
		if (board[k][j] == 'A') {
			return true;
		}
	}
	for (int k = i + 1; k <= n && board[k][j] != 'X'; ++k) {
		if (board[k][j] == 'A') {
			return true;
		}
	}
	return false;
}
