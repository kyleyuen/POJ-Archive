#include <iostream>
#include <string>

using namespace std;

void solve(string& line);

int main()
{
	string line;
	while (getline(cin, line)) {
		if (line == "e/o/i") {
			break;
		}
		solve(line);
	}
	return 0;
}

void solve(string& line)
{
	int index = 1;
	int syllables = 0;
	bool judge = false;
	for (string::size_type i = 0; i != line.size(); ++i) {
		switch (line[i]) {
		case 'a': case 'e': case 'i': case 'o': case 'u': case 'y':
            if (!judge) {
                ++syllables;
                judge = true;
            }
			break;
		case '/':
			if (index == 1 && syllables != 5) {
				cout << 1 << endl;
				return;
			}
			else if (index == 2 && syllables != 7) {
				cout << 2 << endl;
				return;
			}
			++index;
			syllables = 0;
			judge = false;
			break;
		default:
            judge = false;
			break;
		}
	}
	if (syllables != 5) {
		cout << 3 << endl;
	}
	else {
		cout << "Y" << endl;
	}
}
