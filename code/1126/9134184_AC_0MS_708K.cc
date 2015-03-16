#include <iostream>
#include <string>

using namespace std;

bool solve(string& line);

int main()
{
	string line;
	while (cin >> line) {
		if (solve(line)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

bool solve(string& line)
{
	int sentence = 0;
	for (string::reverse_iterator iter = line.rbegin(); iter != line.rend(); ++iter) {
		if ('p' <= *iter && *iter <= 'z') {
			++sentence;
		}
		else if (*iter == 'N') {
		    if (sentence < 1) {
                return false;
		    }
		}
		else if (*iter == 'C' || *iter == 'D' || *iter == 'E' || *iter == 'I') {
			--sentence;
			if (sentence < 1) {
				return false;
			}
		}
		else {
			return false;
		}
	}

	if (sentence == 1) {
		return true;
	}
	else {
		return false;
	}
}
