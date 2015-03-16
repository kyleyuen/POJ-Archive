#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void solve(string number);

int main()
{
	string number;
	while (cin >> number) {
		solve(number);
	}
	return 0;
}

void solve(string number)
{
	int sum = 0;
	int max = 0;
	for (string::size_type j = 0; j != number.size(); ++j) {
		int result;
		if (isupper(number[j])) {
			result = number[j] - 'A' + 10;
		}
		else if (islower(number[j])) {
			result = number[j] - 'a' + 36;
		}
		else {
			result = number[j] - '0';
		}
		sum += result;

		if (max < result) {
			max = result;
		}
	}

	for (int i = max + 1; i <= 62; ++i) {
		if (sum % (i - 1) == 0) {
			cout << i << endl;
			return;
		}
	}

	cout << "such number is impossible!" << endl;
}
