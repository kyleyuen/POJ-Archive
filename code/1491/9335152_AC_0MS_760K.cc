#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void solve(int n);
int gcd(int a, int b);

int main()
{
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		solve(n);
	}
	return 0;
}

void solve(int n)
{
	vector<int> array(n);
	for (int i = 0; i != n; ++i) {
		cin >> array[i];
	}

	int result = 0;
	for (int i = 0; i != n - 1; ++i) {
		for (int j = i + 1; j != n; ++j) {
			if (gcd(array[i], array[j]) == 1) {
				++result;
			}
		}
	}

	if (result == 0) {
		cout << "No estimate for this data set." << endl;
	}
	else {
		cout << setprecision(7) << sqrt(3.0 * n * (n - 1) / result) << endl;
	}
}

int gcd(int a, int b)
{
    int c;
	do {
		c = a % b;
		a = b;
		b = c;
	} while (c != 0);
	return a;
}
