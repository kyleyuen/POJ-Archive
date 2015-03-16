#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solve(string& word);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		string word;
		cin >> word;
		solve(word);
	}
	return 0;
}

void solve(string& word)
{
	vector<int> result;
	for (string::size_type i = 0; i != word.size(); ++i) {
		if (isupper(word[i])) {
			result.push_back((word[i] - 'A') * 2);
		}
		else {
			result.push_back((word[i] - 'a') * 2 + 1);
		}
	}
    sort(result.begin(), result.end());

	while (next_permutation(result.begin(), result.end())) {
		for (vector<int>::size_type i = 0; i != result.size(); ++i) {
			if (result[i] % 2 == 0) {
				cout << (char)(result[i] / 2 + 'A');
			}
			else {
				cout << (char)((result[i] - 1) / 2 + 'a');
			}
		}
		cout << endl;
	}
}
