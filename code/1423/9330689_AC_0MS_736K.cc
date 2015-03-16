#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415926;
const double E = 2.7182818;

int solve(int n);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}

int solve(int n)
{
	return int(log10(sqrt(2 * PI * n)) + n * log10(n / E)) + 1;
}
