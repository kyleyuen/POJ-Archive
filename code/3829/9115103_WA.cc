#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Mission {
	string time;
	int seats;
};

class Compare {
public:
	bool operator() (const Mission& lhs, const Mission& rhs) { return lhs.time < rhs.time; }
};

int x, y;

void solve(int row, int column, int students);
bool find_consecutive_seats(vector< vector<int> >& classroom, vector< vector<bool> >& state, int seats, int row, int column);
bool find_single_seat(vector< vector<int> >& classroom, vector< vector<bool> >& state, int row, int column);

int main()
{
	int row, column, students;
	while (cin >> row >> column >> students) {
		if (row == 0 && column == 0 && students == 0) {
			break;
		}
		solve(row, column, students);
	}
	return 0;
}

void solve(int row, int column, int students)
{
	vector< vector<int> > classroom(row + 1, vector<int>(column + 1));
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			cin >> classroom[i][j];
		}
	}

	vector<Mission> missions(students);
	for (int i = 0; i != students; ++i) {
		cin >> missions[i].time >> missions[i].seats;
	}
	sort(missions.begin(), missions.end(), Compare());

	vector< vector<bool> > state(row + 1, vector<bool>(column + 1, true));
	bool judge = true;
	for (int i = 0; i != students; ++i) {
		if (!judge) {
			cout << -1 << endl;
			continue;
		}

		x = y = 0;
		if (!find_consecutive_seats(classroom, state, missions[i].seats, row, column) && !find_single_seat(classroom, state, row, column)) {
			cout << -1 << endl;
			judge = false;
		}
		else {
			cout << x << ' ' << y << endl;
		}
	}
}

bool find_consecutive_seats(vector< vector<int> >& classroom, vector< vector<bool> >& state, int seats, int row, int column)
{
	int max = 0;
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column - seats + 1; ++j) {
			int sum = 0;
			for (int k = j; k != j + seats; ++k) {
				if (state[i][k]) {
					sum += classroom[i][k];
				}
				else {
					sum = 0;
					j = k;
					break;
				}
			}
			if (max < sum) {
				max = sum;
				x = i;
				y = j;
			}
		}
	}

	if (x == 0 && y == 0) {
		return false;
	}
	else {
		for (int i = 0; i != seats; ++i) {
			state[x][y + i] = false;
		}
		return true;
	}
}

bool find_single_seat(vector< vector<int> >& classroom, vector< vector<bool> >& state, int row, int column)
{
	int max = 0;
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= column; ++j) {
			if (state[i][j] && max < classroom[i][j]) {
				max = classroom[i][j];
				x = i;
				y = j;
			}
		}
	}
	if (x == 0 && y == 0) {
		return false;
	}
	else {
		state[x][y] = false;
		return true;
	}
}
