#include <iostream>
#include <iomanip>

using namespace std;

void solve(int n);

int main()
{
	int n;
	while (cin >> n) {
		solve(n);
	}
	return 0;
}

void solve(int n)
{
	int m = 1;
	for (int i = 1; i <= n; ++i) {
		m *= i;
		while (m % 10 == 0) {
			m /= 10;
		}
		m %= 100000;
	}
	m %= 10;
	cout << setw(5) << n << " -> " << m << endl;
}
