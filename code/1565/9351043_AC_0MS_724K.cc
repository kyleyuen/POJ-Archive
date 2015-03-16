#include <iostream>
#include <string>
#include <cmath>

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
	int base = pow(2, line.size());
	for (string::size_type i = 0; i != line.size(); ++i) {
		result += (line[i] - '0') * (base - 1);
		base /= 2;
	}
	return result;
}
