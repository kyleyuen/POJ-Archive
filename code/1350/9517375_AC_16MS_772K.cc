#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void solve(string& number);
bool check(const string& number);

int main()
{
	string number;
	while (cin >> number) {
		if (number == "-1") {
			break;
		}
		solve(number);
	}
	return 0;
}

void solve(string& number)
{
	cout << "N=" << number << ":" << endl;
	if (number.size() != 4 || !check(number)) {
		cout << "No!!" << endl;
		return;
	}

	int result = -1;
	stringstream ss;
	for (int i = 0; ; ++i) {
		if (result == 0 || result == 6174) {
			cout << "Ok!! " << i << " times" << endl;
			break;
		}

		int first, second;
		sort(number.rbegin(), number.rend());
		ss << number << endl;
		ss >> first;
		sort(number.begin(), number.end());
		ss << number << endl;
		ss >> second;
		result = first - second;
		cout << first << "-" << second << "=" << result << endl;
		ss << result << endl;
		ss >> number;
	}
}

bool check(const string& number)
{
	for (string::size_type i = 0; i != number.size() - 1; ++i) {
		if (number[i] != number[i + 1]) {
			return true;
		}
	}
	return false;
}
