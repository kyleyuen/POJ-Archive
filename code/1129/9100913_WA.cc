#include <iostream>
#include <vector>

using namespace std;

int solve(int stations_number);
void visit(vector< vector<bool> >& stations, vector< vector<bool> >& state, int i, int j);

int main()
{
	int stations_number;
	while (cin >> stations_number) {
		if (stations_number == 0) {
			break;
		}
		int result = solve(stations_number);
		if (result == 1) {
			cout << "1 channel needed." << endl;
		}
		else {
			cout << result << " channels needed." << endl;
		}
	}
}

int solve(int stations_number)
{
	vector< vector<bool> > stations(stations_number, vector<bool>(stations_number, true));
	for (int i = 0; i != stations_number; ++i) {
		string line;
		cin >> line;
		for (string::size_type j = 2; j != line.size(); ++j) {
			stations[i][line[j] - 'A'] = false;
		}
	}

	int result = 0;
	vector< vector<bool> > state(stations_number, vector<bool>(stations_number, true));
	for (int i = 0; i != stations_number; ++i) {
		for (int j = 0; j != stations_number; ++j) {
			if (stations[i][j] && state[i][j]) {
				visit(stations, state, i, j);
				++result;
			}
		}
	}
	return result;
}

void visit(vector< vector<bool> >& stations, vector< vector<bool> >& state, int i, int j)
{
	state[i][j] = state[j][i] = false;
	for (vector<bool>::size_type k = 0; k != stations[i].size(); ++k) {
		if (stations[j][k] && state[j][k]) {
			visit(stations, state, j, k);
		}
	}
}
