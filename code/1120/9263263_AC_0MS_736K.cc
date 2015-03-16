#include <iostream>

using namespace std;

void solve(int days);
void update(int result[22][22], int board[22][22]);

int main()
{
	int days;
	cin >> days;
	solve(days);
	return 0;
}

void solve(int days)
{
	int array[16];
	for (int i = 0; i != 16; ++i) {
		cin >> array[i];
	}

	int result[22][22] = { 0 };
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 20; ++j) {
			cin >> result[i][j];
		}
	}

	int board[22][22] = { 0 };
	for (int k = 0; k != days; ++k) {
		update(result, board);
		for (int i = 1; i <= 20; ++i) {
			for (int j = 1; j <= 20; ++j) {
				result[i][j] += array[board[i][j] + board[i - 1][j] + board[i][j + 1] + board[i + 1][j] + board[i][j - 1]];
				if (result[i][j] > 3) {
					result[i][j] = 3;
				}
				else if (result[i][j] < 0) {
					result[i][j] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 20; ++j) {
			switch (result[i][j]) {
			case 0:
				cout << '.';
				break;
			case 1:
				cout << '!';
				break;
			case 2:
				cout << 'X';
				break;
			case 3:
				cout << '#';
				break;
			}
		}
		cout << endl;
	}
}

void update(int result[22][22], int board[22][22])
{
	for (int i = 1; i <= 20; ++i) {
		for (int j = 1; j <= 20; ++j) {
			board[i][j] = result[i][j];
		}
	}
}
