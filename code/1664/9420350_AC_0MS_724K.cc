#include <iostream>

using namespace std;

int solve(int n, int m);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		int m, n;
		cin >> n >> m;
		cout << solve(n, m) << endl;
	}
	return 0;
}

int solve(int n, int m)
{
	if (n == 1 || m == 1) {
		return 1;
	}

	if (n < m) {
		return solve(n, n);
	}
	else if (n > m) {
		return solve(n, m - 1) + solve(n - m, m);
	}
	else {
		return solve(n, m - 1) + 1;
	}
}
