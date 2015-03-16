#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int m);

int main()
{
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		cout << n << " things taken " << m << " at a time is " << solve(n, m) << " exactly." << endl;
	}
	return 0;
}

int solve(int n, int m)
{
	vector< vector<int> > combination(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; ++i) {
		combination[i][0] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
		    if (j > i) {
                break;
		    }
			combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];
		}
	}
	return combination[n][m];
}
