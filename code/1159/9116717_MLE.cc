#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(string& line, int length);
int LCS(string& lhs, string& rhs, int length);

int main()
{
	int length;
	string line;
	cin >> length >> line;
	cout << solve(line, length) << endl;
	return 0;
}

int solve(string& line, int length)
{
	string reverse(line);
	for (string::size_type i = 0; i != length / 2; ++i) {
		char temp = reverse[i];
		reverse[i] = reverse[length - i - 1];
		reverse[length - i - 1] = temp;
	}
	return length - LCS(line, reverse, length);
}

int LCS(string& lhs, string& rhs, int length)
{
	vector< vector<int> > array(length + 1, vector<int>(length + 1, 0));
	for (int i = 1; i <= length; ++i) {
		for (int j = 1; j <= length; ++j) {
			if (lhs[i - 1] == rhs[j - 1]) {
				array[i][j] = array[i - 1][j - 1] + 1;
			}
			else if (array[i][j - 1] > array[i - 1][j]) {
				array[i][j] = array[i][j - 1];
			}
			else {
				array[i][j] = array[i - 1][j];
			}
		}
	}
	return array[length][length];
}
