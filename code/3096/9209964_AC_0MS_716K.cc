#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pair {
	char first;
	char second;
};

bool solve(string& line);

int main()
{
	string line;
	while (cin >> line) {
		if (line == "*") {
			break;
		}
		cout << line;
		if (solve(line)) {
			cout << " is surprising." << endl;
		}
		else {
			cout << " is NOT surprising." << endl;
		}
	}
	return 0;
}

bool solve(string& line)
{
    if (line.size() == 1) {
        return true;
    }
	for (string::size_type i = 1; i != line.size() - 1; ++i) {
		vector<Pair> tuple;
		for (string::size_type j = 0; j != line.size() - i; ++j) {
			Pair temp;
			temp.first = line[j];
			temp.second = line[j + i];
			for (vector<Pair>::size_type k = 0; k != tuple.size(); ++k) {
				if (tuple[k].first == temp.first && tuple[k].second == temp.second) {
					return false;
				}
			}
			tuple.push_back(temp);
		}
	}
	return true;
}
