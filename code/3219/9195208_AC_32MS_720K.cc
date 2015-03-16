#include <iostream>

using namespace std;

int solve(unsigned n, unsigned k);

int main()
{
	unsigned n, k;
	while (cin >> n >> k) {
		cout << solve(n, k) << endl;
	}
	return 0;
}

int solve(unsigned n, unsigned k)
{
	if ((n & k) == k) {
		return 1;
	}
	else {
		return 0;
	}
}
