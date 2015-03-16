#include <iostream>

using namespace std;

bool solve();

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 0; i != total_cases; ++i) {
		if (solve()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

bool solve()
{
	int year, month, day;
	cin >> year >> month >> day;
	if ((month == 9 || month == 11) && (day == 30)) {
		return true;
	}
	if ((month + day) % 2 == 0) {
		return true;
	}
	return false;
}
