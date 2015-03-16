#include <iostream>
#include <string>

using namespace std;

void solve(const string& line, bool& state);

int main()
{
	string line;
	bool state = true;
	while (getline(cin, line)) {
		solve(line, state);
	}
	return 0;
}

void solve(const string& line, bool& state)
{
	for (string::size_type i = 0; i != line.size(); ++i) {
		if (line[i] == '"') {
			if (state) {
				cout << "``";
			}
			else {
				cout << "''";
			}
			state = !state;
		}
		else {
			cout << line[i];
		}
	}
	cout << endl;
}
