#include <iostream>
#include <vector>

using namespace std;

void solve();
void update(vector< vector<int> >& seats, int row, int column);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 0; i != total_cases; ++i) {
		solve();
		cout << endl;
	}
	return 0;
}

void solve()
{
	int row, column;
	cin >> row >> column;
	vector< vector<int> > seats(row + 1, vector<int>(column + 1));
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			cin >> seats[i][j];
		}
	}
	update(seats, row, column);

	int queries;
	cin >> queries;
	for (int i = 0; i != queries; ++i) {
		int left, top, right, bottom;
		cin >> left >> top >> right >> bottom;
		int result = seats[right][bottom] - seats[top - 1][right] - seats[bottom][left - 1] + seats[top - 1][left - 1];
		cout << "Absolutni hodnota pohodlnosti je " << result << " bodu." << endl;
	}
}

void update(vector< vector<int> >& seats, int row, int column)
{
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			seats[i][j] = seats[i - 1][j] + seats[i][j - 1] - seats[i - 1][j - 1] + seats[i][j];
		}
	}
}
