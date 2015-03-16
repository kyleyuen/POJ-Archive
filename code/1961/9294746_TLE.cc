#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(string& str, int length);
void compute_prefix_function(const string& pattern, vector<int>& state);
bool kmp_matcher(const string& text, const string& pattern);

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
	for (int i = 1; i <= length; ++i) {
		for (int j = 1; j <= i / 2; ++j) {
			if (i % j != 0) {
				continue;
			}
			if (kmp_matcher(str.substr(0, i), str.substr(0, j))) {
				cout << i << ' ' << i / j << endl;
				break;
			}
		}
	}
}

bool kmp_matcher(const string& text, const string& pattern)
{
	int n = text.size();
	int m = pattern.size();

	vector<int> state(m + 1);
	compute_prefix_function(pattern, state);

	vector<int> position;
	int q = 0;
	for (int i = 0; i != n; ++i) {
		while (q > 0 && text[i] != pattern[q]) {
			q = state[q];
		}
		if (text[i] == pattern[q]) {
			++q;
		}
		if (q == m) {
			position.push_back(i - m + 1);
			q = state[q];
		}
	}

    if (position.size() != n / m) {
        return false;
    }

	int shift = 0;
	for (vector<int>::size_type i = 0; i != position.size(); ++i) {
		if (shift != position[i]) {
			return false;
		}
		shift += m;
	}
	return true;
}

void compute_prefix_function(const string& pattern, vector<int>& state)
{
	int m = pattern.size();
	state[0] = 0;
	int k = 0;
	for (int i = 1; i != m; ++i) {
		while (state[i + 1] > 0 && pattern[state[i + 1] - 1] != pattern[k]) {
			state[i + 1] = state[state[i + 1] - 1] + 1;
		}
	}
}
