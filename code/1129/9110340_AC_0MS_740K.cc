#include <iostream>
#include <vector>
#include <list>

using namespace std;

int solve(int stations_number);
void coloring(vector< list<int> >& stations, vector<int>& color, int index);

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
	vector< list<int> > stations(stations_number);
	for (int i = 0; i != stations_number; ++i) {
		string line;
		cin >> line;
		for (string::size_type j = 2; j != line.size(); ++j) {
			stations[i].push_back(line[j] - 'A');
		}
	}

	vector<int> color(stations_number, -1);
	for (int i = 0; i != stations_number; ++i) {
		coloring(stations, color, i);
	}

	int max = 0;
	for (int i = 0; i != stations_number; ++i) {
		if (max < color[i]) {
			max = color[i];
		}
	}
	return max + 1;
}

void coloring(vector< list<int> >& stations, vector<int>& color, int index)
{
	for (int i = 0; i != 4; ++i) {
		bool judge = true;
		for (list<int>::iterator iter = stations[index].begin(); iter != stations[index].end(); ++iter) {
			if (color[*iter] == i) {
				judge = false;
				break;
			}
		}
		if (judge) {
			color[index] = i;
			break;
		}
	}
}
