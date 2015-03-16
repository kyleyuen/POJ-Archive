#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct Team {
	string name;
	int problems[7];
	int solutions;
	int time;
	int mean;
	int index;
};

class Compare {
public:
	bool operator() (const Team& lhs, const Team& rhs) {
		if (lhs.solutions > rhs.solutions) {
			return true;
		}
		if ((lhs.solutions == rhs.solutions) && (lhs.time < rhs. time)) {
			return true;
		}
		if ((lhs.solutions == rhs.solutions) && (lhs.time == rhs. time) && (lhs.mean < rhs.mean)) {
			return true;
		}
		if ((lhs.solutions == rhs.solutions) && (lhs.time == rhs. time) && (lhs.mean == rhs.mean) && lhs.name < rhs.name) {
			return true;
		}
		return false;
	}
};

unsigned length = 0;

void solve(int teams);
int get_digits(int n);

int main()
{
	int counter = 1;
	int teams;
	while (cin >> teams) {
		if (teams == 0) {
			break;
		}
		cout << "CONTEST " << counter << endl;
		solve(teams);
		++counter;
	}
	return 0;
}

void solve(int teams)
{
	vector<Team> ranklist(teams);
	for (int i = 0; i != teams; ++i) {
		cin >> ranklist[i].name;
		if (length < ranklist[i].name.size()) {
			length = ranklist[i].name.size();
		}

		int total_time = 0;
		int solved = 0;
		double mean = 0;
		for (int j = 0; j != 7; ++j) {
			cin >> ranklist[i].problems[j];
			total_time += ranklist[i].problems[j];
			if (ranklist[i].problems[j] > 0) {
				++solved;
				mean += log((double)ranklist[i].problems[j]);
			}
		}
		ranklist[i].time = total_time;
		ranklist[i].solutions = solved;
		if (mean == 0) {
			ranklist[i].mean = 0;
		}
		else {
			ranklist[i].mean = (int)(exp(mean / solved) + 0.5);
		}
	}

	sort(ranklist.begin(), ranklist.end(), Compare());
	int id = 1;
	int gap = 1;
	ranklist[0].index = 1;
	for (int i = 1; i != teams; ++i) {
		if (ranklist[i - 1].solutions == ranklist[i].solutions && ranklist[i - 1].time == ranklist[i].time && ranklist[i - 1].mean == ranklist[i].mean) {
			ranklist[i].index = ranklist[i - 1].index;
			++gap;
		}
		else {
			id += gap;
			gap = 1;
			ranklist[i].index = id;
		}
	}

	for (int i = 0; i != teams; ++i) {
		if (ranklist[i].index < 10) {
			cout << 0;
		}
		cout << ranklist[i].index << ' ' << ranklist[i].name;
		for (unsigned j = 0; j < length - ranklist[i].name.size(); ++j) {
			cout << ' ';
		}
		cout << ' ' << ranklist[i].solutions << ' ';
		for (int k = get_digits(ranklist[i].time); k != 4; ++k) {
            cout << ' ';
        }
		cout << ranklist[i].time;
		for (int k = get_digits(ranklist[i].mean); k != 4; ++k) {
            cout << ' ';
        }
		cout << ranklist[i].mean;
		for (int j = 0; j != 7; ++j) {
            for (int k = get_digits(ranklist[i].problems[j]); k != 4; ++k) {
                cout << ' ';
            }
			cout << ranklist[i].problems[j];
		}
		cout << endl;
	}
}

int get_digits(int n)
{
    if (n < 10) {
        return 1;
    }
    if (n < 100) {
        return 2;
    }
    if (n < 1000) {
        return 3;
    }
    return 4;
}
