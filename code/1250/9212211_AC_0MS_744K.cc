#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(int beds, const string& salon);

int main()
{
	int beds;
	string salon;
	while (cin >> beds) {
		if (beds == 0) {
			break;
		}
		cin >> salon;
		solve(beds, salon);
	}
	return 0;
}

void solve(int beds, const string& salon)
{
	int result = 0;
	int used = 0;
	vector<bool> state(26, false);
	for (string::size_type i = 0; i != salon.size(); ++i) {
		if (!state[salon[i] - 'A']) {
			if (used == beds) {
				++result;
				++i;
				continue;
			}
			state[salon[i] - 'A'] = true;
			++used;
		}
		else {
			state[salon[i] - 'A'] = false;
			--used;
		}
	}
	if (result == 0) {
		cout << "All customers tanned successfully." << endl;
	}
	else {
		cout << result << " customer(s) walked away." << endl;
	}
}
