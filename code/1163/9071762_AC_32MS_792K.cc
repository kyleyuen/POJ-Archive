#include <iostream>
#include <vector>

using namespace std;

int solve(int n);

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}

int solve(int n)
{
	vector< vector<int> > triangle(n, vector<int>(n));
	for (int i = 0; i != n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> triangle[i][j];
		}
	}

	vector< vector<int> > sumation(n, vector<int>(n));
	sumation[0][0] = triangle[0][0];
	for (int i = 1; i != n; ++i) {
		sumation[i][0] = sumation[i - 1][0] + triangle[i][0];
	}
	for (int i = 1; i != n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (sumation[i - 1][j] < sumation[i - 1][j - 1]) {
				sumation[i][j] = sumation[i - 1][j - 1] + triangle[i][j];
			}
			else {
				sumation[i][j] = sumation[i - 1][j] + triangle[i][j];
			}
		}
	}
	int max = 0;
	for (int i = 0; i != n; ++i) {
		if (sumation[n - 1][i] > max) {
			max = sumation[n - 1][i];
		}
	}
	return max;
}
