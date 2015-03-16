#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(string& str);
void compute_prefix_function(const string& pattern, vector<int>& state);

int main()
{
	string line;
	while (cin >> line) {
		if (line == ".") {
			break;
		}
		cout << solve(line) << endl;
	}
	return 0;
}

int solve(string& str)
{
	int length = str.size();
	vector<int> state(length + 1);
	compute_prefix_function(str, state);
	int gap = length - state[length];
	if (length % gap == 0) {
		return length / gap;
	}
	else {
		return 1;
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
