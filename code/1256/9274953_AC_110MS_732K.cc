#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class Compare {
public:
	bool operator() (char lhs, char rhs) {
		if (isupper(lhs) && islower(rhs)) {
			lhs += 32;
			if (lhs == rhs) {
				return true;
			}
		}
		else if (islower(lhs) && isupper(rhs)) {
			rhs += 32;
			if (lhs == rhs) {
				return false;
			}
		}
		return lhs < rhs;
	}
};

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
	sort(word.begin(), word.end(), Compare());
	cout << word << endl;
	while (next_permutation(word.begin(), word.end(), Compare())) {
        cout << word << endl;
	}
}
