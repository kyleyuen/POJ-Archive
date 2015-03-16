#include <iostream>

using namespace std;

int solve(int n);

int main()
{
	int n;
	while (cin >> n) {
		cout << solve(n - 1) << endl;
	}
	return 0;
}

int solve(int n)
{
	int result = n;
	for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
        {
            n /= i;
            result = result - result / i;
            while (n % i == 0) {
                n /= i;
			}
        }
    }
    if (n > 1) {
        result = result - result / n;
	}
    return result;
}
