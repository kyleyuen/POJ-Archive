#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int number);

int main()
{
	int number;
	while (cin >> number) {
		solve(number);
	}
	return 0;
}

void solve(int number)
{
	vector<string> filenames(number);
	unsigned length = 0;
	for (int i = 0; i != number; ++i) {
		cin >> filenames[i];
		if (length < filenames[i].size()) {
			length = filenames[i].size();
		}
	}

	int row;
	int column;
	for (int i = 1; i <= number / 2; ++i) {
		column = (number % i == 0) ? number / i : number / i + 1;
		if (column * (length + 2) - 2 <= 60) {
			row = i;
			break;
		}
	}

	sort(filenames.begin(), filenames.end());
	for (int i = 0; i != 60; ++i) {
        cout << '-';
    }
    cout << endl;
	for (int i = 0; i != row; ++i) {
		for (int j = 0; j != column; ++j) {
			if (i + row * j >= filenames.size()) {
				break;
			}
			cout << setiosflags(ios::left) << setw(length + 2) << filenames[i + row * j];
		}
		cout << endl;
	}
}
