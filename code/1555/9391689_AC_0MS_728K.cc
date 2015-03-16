#include <iostream>

using namespace std;

void solve();

int array[9];

int main()
{
	while (cin >> array[0]) {
		for (int i = 1; i != 9; ++i) {
			cin >> array[i];
		}
		solve();
	}
	return 0;
}

void solve()
{
	int index = 0;
	while (array[index] == 0) {
		++index;
	}
	if (index <= 6) {
		if (array[index] == -1) {
			cout << '-';
		}
		else if (array[index] != 1) {
			cout << array[index];
		}
		cout << "x^" << 8 - index << ' ';
	}
	else if (index == 7) {
		if (array[index] == -1) {
			cout << '-';
		}
		else if (array[index] != 1) {
			cout << array[index];
		}
		cout << "x ";
	}
	else if (index == 8) {
		cout << array[index];
	}
	else {
		cout << '0';
	}
	++index;

	while (index <= 6) {
		if (array[index] > 0) {
			cout << "+ ";
			if (array[index] != 1) {
				cout << array[index];
			}
			cout << "x^" << 8 - index << ' ';
		}
		else if (array[index] < 0) {
			cout << "- ";
			if (array[index] != -1) {
				cout << -array[index];
			}
			cout << "x^" << 8 - index << ' ';
		}
		++index;
	}
	if (index == 7) {
		if (array[index] > 0) {
			cout << "+ ";
			if (array[index] != 1) {
				cout << array[index];
			}
			cout << "x ";
		}
		else if (array[index] < 0) {
			cout << "- ";
			if (array[index] != -1) {
				cout << -array[index];
			}
			cout << "x ";
		}
		++index;
	}
	if (index == 8) {
		if (array[index] > 0) {
			cout << "+ " << array[index];
		}
		else if (array[index] < 0) {
			cout << "- " << -array[index];
		}
	}
	cout << endl;
}
