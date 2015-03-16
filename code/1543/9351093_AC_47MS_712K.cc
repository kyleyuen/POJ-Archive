#include <iostream>

using namespace std;

void solve(int n);

int main()
{
	int n;
	cin >> n;
	solve(n);
	return 0;
}

void solve(int n)
{
	for (int a = 2; a <= n; ++a) {
		for (int b = 2; b < n; ++b) {
			for (int c = b + 1; c < n; ++c) {
				for (int d = c + 1; d < n; ++d) {
					if (a*a*a == b*b*b + c*c*c + d*d*d) {
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
					}
				}
			}
		}
	}
}
