#include <iostream>
#include <iomanip>

using namespace std;

double solve();

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		cout << "Scenario #:" << i << endl;
		cout << fixed << setprecision(2) << solve() << endl << endl;
	}
	return 0;
}

double solve()
{
	int m, n;
	cin >> m >> n;
	if (m * n % 2 == 0) {
		return m * n;
	}
	else {
		return m * n + 0.41;
	}
}
