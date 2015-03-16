#include <iostream>

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
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    if (n == 2) {
        cout << 1 << endl;
        cout << 2 << ' ' << 1 << ' ' << 0 << endl;
        return;
    }

    cout << (n + 2) / 2 << endl;
	int index = n;
	if (index % 2 == 0) {
		--index;
	}
	int position = n - 2;
	while (index != 1) {
		cout << index / 2 << ' ' << 2 << ' ' << position << endl;
		index -= 2;
		--position;
	}
	if (n % 2 == 0) {
		cout << 1 << ' ' << 1 << ' ' << 1 << endl;
		cout << 3 << ' ' << (n - 1) / 2 << ' ' << n / 2 + 1 << endl;
	}
	else {
		cout << 2 << ' ' << n / 2 << ' ' << n / 2 + 1 << endl;
	}
}
