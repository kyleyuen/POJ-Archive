#include <iostream>
#include <string>

using namespace std;

int board[101][101] = { 0 };

void solve();

int main()
{
	int commands;
	cin >> commands;
	for (int i = 0; i != commands; ++i) {
		solve();
	}
	return 0;
}

void solve()
{
	string command;
	cin >> command;
	int x, y, l;
	cin >> x >> y >> l;

	if (command == "WHITE") {
		for (int i = x; i != x + l; ++i) {
			for (int j = y; j != y + l; ++j) {
				board[i][j] = 0;
			}
		}
	}
	else if (command == "BLACK") {
		for (int i = x; i != x + l; ++i) {
			for (int j = y; j != y + l; ++j) {
				board[i][j] = 1;
			}
		}
	}
	else {
		int result = 0;
		for (int i = x; i != x + l; ++i) {
			for (int j = y; j != y + l; ++j) {
				if (board[i][j]) {
					++result;
				}
			}
		}
		cout << result << endl;
	}
}
