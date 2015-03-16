#include <iostream>
#include <string>

using namespace std;

char board[33][33];

void initial();
void print();
void solve(int x, int y);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		initial();

		int x, y;
		cin >> x >> y;
		solve(y, x);

		cout << "Bitmap #" << i << endl;
		print();
		cout << endl;
	}
	return 0;
}

void initial()
{
	for (int i = 1; i <= 32; ++i) {
		for (int j = 1; j <= 32; ++j) {
			board[i][j] = '.';
		}
	}
}

void print()
{
	for (int i = 32; i >= 1; --i) {
		for (int j = 1; j <= 32; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

void solve(int x, int y)
{
	string path;
	cin >> path;
	for (string::size_type i = 0; path[i] != '.'; ++i) {
		switch (path[i]) {
		case 'N':
			board[x + 1][y + 1] = 'X';
			++x;
			break;
		case 'E':
			board[x][y + 1] = 'X';
			++y;
			break;
		case 'S':
			board[x][y] = 'X';
			--x;
			break;
		case 'W':
			board[x + 1][y] = 'X';
			--y;
			break;
		}
	}
}
