#include <iostream>
#include <iomanip>

using namespace std;

void solve(int n);

int main()
{
	int n;
	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		solve(n);
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

void solve(int n)
{
	int sum = 0;
	for (int i = 1; i <= n / 2; ++i) {
		if (n % i == 0) {
			sum += i;
		}
	}

	cout << setw(5) << n << "  ";
	if (sum > n) {
		cout << "ABUNDANT" << endl;
	}
	else if (sum < n) {
		cout << "DEFICIENT" << endl;
	}
	else {
		cout << "PERFECT" << endl;
	}
}
