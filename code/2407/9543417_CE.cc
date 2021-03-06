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
	if (n == 1) {
		return 0;
	}
	
	int result = n;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			result = result * (i - 1) / i;
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n != 1) {
		result = result * (i - 1) / i;
	}
	return result;
}