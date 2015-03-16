#include <iostream>

using namespace std;

int main()
{
	long long a;
	cin >> a;
	long long m, n;
	for (m = a; m != 0; --m) {
		if ((a * a + 1) % m == 0) {
			break;
		}
	}
	n = (a * a + 1) / m;
	cout << 2 * a + m + n << endl;
	return 0;
}
