#include <iostream>
#include <iomanip>

using namespace std;

double solve(int n);

int main()
{
	cout << "Cards  Overhang" << endl;
	int n;
	while (cin >> n) {
		cout << setw(5) << n << setw(10) << fixed << setprecision(3) << solve(n) << endl;
	}
	return 0;
}

double solve(int n)
{
	double result = 0;
	for (int i = 1; i <= n; ++i) {
		result += 0.5 / i;
	}
	return result;
}
