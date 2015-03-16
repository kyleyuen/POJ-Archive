#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solve(int row, int column);
void visit(vector< vector<char> >& matrix, set<char>& letter, int i, int j, int& max, int length);

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

	int max = 0;
    set<char> letter;
    letter.insert('#');
    visit(matrix, letter, 1, 1, max, 1);
	return max;
}

void visit(vector< vector<char> >& matrix, set<char>& letter, int i, int j, int& max, int length)
{
	if (max < length) {
		max = length;
	}

	letter.insert(matrix[i][j]);
	if (letter.find(matrix[i - 1][j]) == letter.end()) {
		visit(matrix, letter, i - 1, j, max, length + 1);
	}
	if (letter.find(matrix[i][j + 1]) == letter.end()) {
		visit(matrix, letter, i, j + 1, max, length + 1);
	}
	if (letter.find(matrix[i + 1][j]) == letter.end()) {
		visit(matrix, letter, i + 1, j, max, length + 1);
	}
	if (letter.find(matrix[i][j - 1]) == letter.end()) {
		visit(matrix, letter, i, j - 1, max, length + 1);
	}
	letter.erase(matrix[i][j]);
}
