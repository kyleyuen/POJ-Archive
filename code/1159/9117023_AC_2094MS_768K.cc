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
	for (int i = 0; i != length / 2; ++i) {
		char temp = reverse[i];
		reverse[i] = reverse[length - i - 1];
		reverse[length - i - 1] = temp;
	}
	return length - LCS(line, reverse, length);
}

int LCS(string& lhs, string& rhs, int length)
{
	vector<int> array(length + 1, 0);
	for (int i = 1; i <= length; ++i) {
	    int a = array[0];
		for (int j = 1; j <= length; ++j) {
		    int b = array[j];
			if (lhs[i - 1] == rhs[j - 1]) {
				array[j] = a + 1;
			}
			else if (array[j] < array[j - 1]) {
				array[j] = array[j - 1];
			}
			a = b;
		}
	}
	return array[length];
}
