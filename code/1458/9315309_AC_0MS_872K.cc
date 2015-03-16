#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(string& lhs, string& rhs);

int main()
{
	string a, b;
	while (cin >> a >> b) {
		cout << solve(a, b) << endl;
	}
}

int solve(string& lhs, string& rhs)
{
	int m = lhs.size();
	int n = rhs.size();
	vector< vector<int> > array(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (lhs[i - 1] == rhs[j - 1]) {
				array[i][j] = array[i - 1][j - 1] + 1;
			}
			else if (array[i - 1][j] < array[i][j - 1]) {
				array[i][j] = array[i][j - 1];
			}
			else {
				array[i][j] = array[i - 1][j];
			}
		}
	}
	return array[m][n];
}
