#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string& solve(string& line);

int main()
{
	string start, end;
	string line;
	while (true) {
		getline(cin, start);
		if (start == "ENDOFINPUT") {
			break;
		}
		getline(cin, line);
		getline(cin, end);
		cout << solve(line) << endl;
	}
	return 0;
}

string& solve(string& line)
{
	for (string::iterator iter = line.begin(); iter != line.end(); ++iter) {
		if (!isupper(*iter)) {
			continue;
		}
		switch (*iter) {
		case 'A':
			*iter = 'V';
			break;
		case 'B':
			*iter = 'W';
			break;
		case 'C':
			*iter = 'X';
			break;
		case 'D':
			*iter = 'Y';
			break;
		case 'E':
			*iter = 'Z';
			break;
		default:
			*iter -= 5;
			break;
		}
	}
	return line;
}
