#include <iostream>

using namespace std;

int solve(int n);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 0; i != total_cases; ++i) {
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}

int solve(int n)
{
	int sum = 0;
	for (int i = 1; i * i <= n; ++i) {
		++sum;
	}
	return sum;
}
