#include <iostream>
#include <algorithm>

using namespace std;

bool solve();

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
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
	int disks_number;
	cin >> disks_number;

	int odd = 0;
	int even = 0;
	for (int i = 1; i <= disks_number; ++i) {
		int temp;
		cin >> temp;
		if (temp == 1) {
			if (i % 2 == 1) {
				++odd;
			}
			else {
				++even;
			}
		}
	}

    if (disks_number % 2 == 1) {
		return true;
	}
	if (abs(odd - even) <= 1) {
		return true;
	}
	return false;
}
