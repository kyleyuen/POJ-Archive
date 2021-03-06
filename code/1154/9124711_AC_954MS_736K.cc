#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solve(int row, int column);
void visit(vector< vector<char> >& matrix, vector< vector<bool> >& state, set<char>& letter, int i, int j, int& result, int length);

int main()
{
	int row, column;
	cin >> row >> column;
	cout << solve(row, column) << endl;
	return 0;
}

int solve(int row, int column)
{
	vector< vector<char> > matrix(row + 2, vector<char>(column + 2, '#'));
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			cin >> matrix[i][j];
		}
	}

	vector< vector<bool> > state(row + 2, vector<bool>(column + 2, true));
	for (int i = 0; i != row + 2; ++i) {
		state[i][0] = state[i][column + 1] = false;
	}
	for (int i = 0; i != column + 2; ++i) {
		state[0][i] = state[row + 1][i] = false;
	}

	int result = 0;
	set<char> letter;
	visit(matrix, state, letter, 1, 1, result, 1);
	return result;
}

void visit(vector< vector<char> >& matrix, vector< vector<bool> >& state, set<char>& letter, int i, int j, int& result, int length)
{
	if (result < length) {
		result = length;
	}

	state[i][j] = false;
	letter.insert(matrix[i][j]);
	if (state[i - 1][j] && letter.find(matrix[i - 1][j]) == letter.end()) {
		visit(matrix, state, letter, i - 1, j, result, length + 1);
	}
	if (state[i][j + 1] && letter.find(matrix[i][j + 1]) == letter.end()) {
		visit(matrix, state, letter, i, j + 1, result, length + 1);
	}
	if (state[i + 1][j] && letter.find(matrix[i + 1][j]) == letter.end()) {
		visit(matrix, state, letter, i + 1, j, result, length + 1);
	}
	if (state[i][j - 1] && letter.find(matrix[i][j - 1]) == letter.end()) {
		visit(matrix, state, letter, i, j - 1, result, length + 1);
	}
	state[i][j] = true;
	letter.erase(matrix[i][j]);
}
