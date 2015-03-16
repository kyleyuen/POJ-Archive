#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(string& str, int length);
void compute_prefix_function(const string& pattern, vector<int>& state);

int main()
{
	int length;
	int counter = 0;
	while (cin >> length) {
		if (length == 0) {
			break;
		}
		string str;
		cin >> str;

		++counter;
		cout << "Test case #" << counter << endl;
		solve(str, length);
		cout << endl;
	}
	return 0;
}

void solve(string& str, int length)
{
	vector<int> state(length + 1);
	compute_prefix_function(str, state);
	for (int i = 1; i <= length; ++i) {
		if (i % (i - state[i]) == 0 && state[i] != 0) {
			cout << i << ' ' << i / (i - state[i]) << endl;
		}
	}
}

void compute_prefix_function(const string& pattern, vector<int>& state)
{
	int m = pattern.size();
	state[1] = 0;
	int k = 0;
	for (int i = 1; i != m; ++i) {
		while (k > 0 && pattern[i] != pattern[k]) {
			k = state[k];
		}
		if (pattern[i] == pattern[k]) {
			++k;
		}
		state[i + 1] = k;
	}
}
