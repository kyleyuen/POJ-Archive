#include <iostream>

using namespace std;

void solve();
bool isDiffer(int a, int b, int c, int d);
bool isMultiple(int a, int b, int c, int d);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		solve();
	}
	return 0;
}

void solve()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (isDiffer(a, b, c, d)) {
		cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << d + d - c << endl;
	}
	else if (isMultiple(a, b, c, d)) {
		cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << d * d / c << endl;
	}
}

bool isDiffer(int a, int b, int c, int d)
{
	return (b - a == c - b) && (c - b == d - c);
}

bool isMultiple(int a, int b, int c, int d)
{
	return (b / a == c / b) && (c / b == d / c);
}
