#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(const string& line);
void print(vector<int>& state, int k);
void compute_prefix_function(const string& pattern, vector<int>& state);

int main()
{
	string line;
	while (cin >> line) {
		solve(line);
	}
	return 0;
}

void solve(const string& line)
{
	int m = line.size();
	vector<int> state(m + 1);
	compute_prefix_function(line, state);
	print(state, m);
	cout << endl;
}

void print(vector<int>& state, int k)
{
	if (k == 0) {
		return;
	}
	print(state, state[k]);
	cout << k << ' ';
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
