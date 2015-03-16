#include <iostream>

using namespace std;

int solve(int n);

int main()
{
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << solve(n) << endl;
	}
	return 0;
}

int solve(int n)
{
	int result = n;
	for (int i = 2; i <= n; ++i) {
		if (n % i == 0) {
			result = result * (i - 1) / i;
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	return result;
}