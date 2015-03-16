#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void solve(int step, int mod);
bool check(vector<bool>& state);

int main()
{
	int step, mod;
	while (cin >> step >> mod) {
		solve(step, mod);
	}
}

void solve(int step, int mod)
{
	vector<bool> state(mod, false);
	int seed = 0;
	while (!state[seed]) {
		state[seed] = true;
		seed = (seed + step) % mod;
	}

	cout << setw(10) << step;
	cout << setw(10) << mod;
	cout << "     ";
	if (check(state)) {
		cout << "Good Choice" << endl;
	}
	else {
		cout << "Bad Choice" << endl;
	}
	cout << endl;
}

bool check(vector<bool>& state)
{
	for (vector<bool>::size_type i = 0; i != state.size(); ++i) {
		if (!state[i]) {
			return false;
		}
	}
	return true;
}
