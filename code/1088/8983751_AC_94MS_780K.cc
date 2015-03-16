#include <iostream>
#include <vector>

using namespace std;

int solve(int row, int column);
void visit(vector< vector<int> >& area, vector< vector<int> >& distance, int i, int j);

int main()
{
	int row, column;
	cin >> row >> column;
	cout << solve(row, column) << endl;

	return 0;
}

int solve(int row, int column)
{
	vector< vector<int> > area(row + 2, vector<int>(column + 2));
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			cin >> area[i][j];
		}
	}

	vector< vector<int> > distance(row + 2, vector<int>(column + 2, 0));
	for (int i = 0; i <= row + 1; ++i) {
		distance[i][0] = -1;
		distance[i][column + 1] = -1;
	}
	for (int i = 0; i <= column + 1; ++i) {
		distance[0][i] = -1;
		distance[row + 1][i] = -1;
	}

	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			if (distance[i][j] == 0) {
				visit(area, distance, i, j);
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			if (max < distance[i][j]) {
				max = distance[i][j];
			}
		}
	}
	return max;
}

void visit(vector< vector<int> >& area, vector< vector<int> >& distance, int i, int j)
{
	++distance[i][j];
	int max = 0;
	if (area[i][j - 1] < area[i][j]) {
		if (distance[i][j - 1] == 0) {
			visit(area, distance, i, j - 1);
		}
		if (max < distance[i][j - 1]) {
            max = distance[i][j - 1];
        }
	}
	if (area[i - 1][j] < area[i][j]) {
		if (distance[i - 1][j] == 0) {
			visit(area, distance, i - 1, j);
		}
        if (max < distance[i - 1][j]) {
            max = distance[i - 1][j];
        }

	}
	if (area[i][j + 1] < area[i][j]) {
		if (distance[i][j + 1] == 0) {
			visit(area, distance, i, j + 1);
		}
		if (max < distance[i][j + 1]) {
            max = distance[i][j + 1];
        }
	}
	if (area[i + 1][j] < area[i][j]) {
		if (distance[i + 1][j] == 0) {
			visit(area, distance, i + 1, j);
		}
		if (max < distance[i + 1][j]) {
            max = distance[i + 1][j];
        }
	}
    distance[i][j] += max;
}
