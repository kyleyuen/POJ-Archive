#include <iostream>
#include <vector>

using namespace std;

void solve(int row, int column);
void visit(vector< vector<char> >& castle, vector< vector<bool> >& state, int& area, int i, int j);

int main()
{
	int row, column;
	cin >> row >> column;
	solve(row, column);
	return 0;
}

void solve(int row, int column)
{
	vector< vector<char> > castle(row * 2 + 1, vector<char>(column * 2 + 1, '0'));
	for (int i = 1; i <= row * 2 - 1; i += 2) {
		for (int j = 1; j <= column * 2 - 1; j += 2) {
			int temp;
			cin >> temp;
			if (temp & 1) {
				castle[i - 1][j - 1] = castle[i][j - 1] = castle[i + 1][j - 1] = '#';
			}
			if (temp & 2) {
				castle[i - 1][j - 1] = castle[i - 1][j] = castle[i - 1][j + 1] = '#';
			}
			if (temp & 4) {
				castle[i - 1][j + 1] = castle[i][j + 1] = castle[i + 1][j + 1] = '#';
			}
			if (temp & 8) {
				castle[i + 1][j - 1] = castle[i + 1][j] = castle[i + 1][j + 1] = '#';
			}
		}
	}

	int room = 0;
	int max_size = 0;
	vector< vector<bool> > state(row * 2 + 1, vector<bool>(column * 2 + 1, true));
	for (int i = 1; i <= row * 2 - 1; i += 2) {
		for (int j = 1; j <= column * 2 - 1; j += 2) {
			if (state[i][j]) {
				int area = 0;
				visit(castle, state, area, i, j);
				if (area > max_size) {
					max_size = area;
				}
				++room;
			}
		}
	}
	cout << room << endl;
	cout << max_size << endl;
}

void visit(vector< vector<char> >& castle, vector< vector<bool> >& state, int& area, int i, int j)
{
	state[i][j] = false;
	if (i & 1 && j & 1) {
        ++area;
	}
	if (state[i - 1][j] && castle[i - 1][j] == '0') {
		visit(castle, state, area, i - 1, j);
	}
	if (state[i][j + 1] && castle[i][j + 1] == '0') {
		visit(castle, state, area, i, j + 1);
	}
	if (state[i + 1][j] && castle[i + 1][j] == '0') {
		visit(castle, state, area, i + 1, j);
	}
	if (state[i][j - 1] && castle[i][j - 1] == '0') {
		visit(castle, state, area, i, j - 1);
	}
}
