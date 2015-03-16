#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

void solve(int row, int column, int entry);

int main()
{
	int row, column, entry;
	while (cin >> row >> column >> entry) {
		if (row == 0 && column == 0 && entry == 0) {
			break;
		}
		solve(row, column, entry);
	}
	return 0;
}

void solve(int row, int column, int entry)
{
	vector< vector<char> > board(row + 2, vector<char>(column + 2, 'O'));
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			cin >> board[i][j];
		}
	}

	vector< vector<bool> > state(row + 2, vector<bool>(column + 2, true));
	vector< vector<Point> > parent(row + 2, vector<Point>(column + 2));
	Point previous, current;
	current.x = 1;
	current.y = entry;
	int path = -1;
	while (state[current.x][current.y]) {
		state[current.x][current.y] = false;
		++path;
		previous = current;
		switch (board[current.x][current.y]) {
		case 'N':
			--current.x;
			break;
		case 'E':
			++current.y;
			break;
		case 'S':
			++current.x;
			break;
		case 'W':
			--current.y;
			break;
		default:
			cout << path << " step(s) to exit" << endl;
			return;
		}
		parent[current.x][current.y].x = previous.x;
		parent[current.x][current.y].y = previous.y;
	}

	int loop = 1;
	while (previous.x != current.x || previous.y != current.y) {
		++loop;
		int temp = previous.x;
		previous.x = parent[previous.x][previous.y].x;
		previous.y = parent[temp][previous.y].y;
	}
	cout << path - loop + 1 << " step(s) before a loop of " << loop << " step(s)" << endl;
}
