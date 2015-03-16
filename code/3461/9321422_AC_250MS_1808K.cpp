#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve();
int kmp_matcher(const string& text, const string& pattern);
void compute_prefix_function(const string& pattern, vector<int>& state);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		cout << solve() << endl;
	}
	return 0;
}

int solve()
{
	string text, pattern;
	cin >> pattern >> text;
	return kmp_matcher(text, pattern);
}

int kmp_matcher(const string& text, const string& pattern)
{
	int n = text.size();
	int m = pattern.size();

	vector<int> state(m + 1);
	compute_prefix_function(pattern, state);

	int result = 0;
	int q = 0;
	for (int i = 0; i != n; ++i) {
		while (q > 0 && text[i] != pattern[q]) {
			q = state[q];
		}
		if (text[i] == pattern[q]) {
			++q;
		}
		if (q == m) {
			++result;
			q = state[q];
		}
	}
	return result;
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
