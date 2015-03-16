#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void solve();
void find_word(set<string>& dictionary, string& line);

int main()
{
	solve();
	return 0;
}

void solve()
{
	set<string> dictionary;
	string line;
	while (cin >> line) {
		if (line == "XXXXXX") {
			break;
		}
		dictionary.insert(line);
	}

	while (cin >> line) {
		if (line == "XXXXXX") {
			break;
		}
		sort(line.begin(), line.end());
		find_word(dictionary, line);
		cout << "******" << endl;
	}
}

void find_word(set<string>& dictionary, string& line)
{
	bool judge = false;
	do {
		if (dictionary.find(line) != dictionary.end()) {
			cout << line << endl;
			judge = true;
		}
	} while (next_permutation(line.begin(), line.end()));
	if (!judge) {
		cout << "NOT A VALID WORD" << endl;
	}
}
