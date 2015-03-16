#include <iostream>
#include <string>

using namespace std;

int solve(const string& line);

int main()
{
	string line;
	while (cin >> line) {
		if (line == "0") {
			break;
		}
		cout << solve(line) << endl;
	}
	return 0;
}

int solve(const string& line)
{
	int result = 0;
	for (string::const_iterator iter = line.begin(); iter != line.end(); ++iter) {
		result += *iter - '0';
	}
	result %= 9;
	if (result == 0) {
		result = 9;
	}
	return result;
}
