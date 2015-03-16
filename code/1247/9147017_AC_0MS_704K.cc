#include <iostream>
#include <vector>

using namespace std;

void solve(int n);

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
	vector<int> guests(n);
	int sum = 0;
	for (int i = 0; i != n; ++i) {
		cin >> guests[i];
		sum += guests[i];
	}

	int base = 0;
	int index = 0;
	for (int i = 0; i != n; ++i) {
		if (base * 2 == sum) {
			break;
		}
		base += guests[i];
		++index;
	}
	if (index == n) {
		cout << "No equal partitioning." << endl;
	}
	else {
		cout << "Sam stops at position " << index << " and Ella stops at position " << index + 1 << "." << endl;
	}
}
