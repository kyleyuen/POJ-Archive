#include <iostream>
#include <string>

using namespace std;

int solve(const string& line);
int minimumRepresentation(const string& str);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		string line;
		cin >> line;
		cout << solve(line) << endl;
	}
	return 0;
}

int solve(const string& line)
{
	return minimumRepresentation(line) + 1;
}

int minimumRepresentation(const string& str)
{
	int i = 0, j = 1, k = 0;
	int length = str.size();
	while (i < length && j < length && k < length) {
		int temp = str[(i + k) % length] - str[(j + k) % length];
		if (temp == 0) {
			++k;
		}
		else {
			if (temp > 0) {
				i += k + 1;
			}
			else {
				j += k + 1;
			}
			if (i == j) {
				++j;
			}
			k = 0;
		}
	}
	return i < j ? i : j;
}
