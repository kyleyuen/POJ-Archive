#include <iostream>

using namespace std;

void solve();

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
	int x, y;
	cin >> x >> y;
	if (x != y && x != y + 2) {
		cout << "No Number" << endl;
		return;
	}

	if (x % 2 == 0) {
		cout << x + y << endl;
	}
	else {
		cout << x + y - 1 << endl;
	}
}
