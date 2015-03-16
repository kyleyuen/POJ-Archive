#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(const string& lhs, const string& rhs);
int not_LCS(const string& lhs, const string& rhs);
int gcd(int a, int b);

int main()
{
	string line;
	while (cin >> line) {
		if (line == "-1") {
			break;
		}
		string str;
		cin >> str;
		solve(line, str);
	}
	return 0;
}

void solve(const string& lhs, const string& rhs)
{
	cout << "appx(" << lhs << "," << rhs << ") = ";
	if (lhs == rhs) {
		cout << 1 << endl;
		return;
	}

	int numerator = not_LCS(lhs, rhs) * 2;
	int denominator = lhs.size() + rhs.size();
	int divisor = gcd(numerator, denominator);
	numerator /= divisor;
	denominator /= divisor;
	if (numerator == 0) {
		cout << 0 << endl;
	}
	else {
		cout << numerator << "/" << denominator << endl;
	}
}

int not_LCS(const string& lhs, const string& rhs)
{
	int result = 0;
	for (string::size_type i = 0; i != lhs.size(); ++i) {
		for (string::size_type j = 0; j != rhs.size(); ++j) {
			int length = 0;
			for (string::size_type m = i, n = j; m != lhs.size() && n != rhs.size(); ++m, ++n) {
				if (lhs[m] == rhs[n]) {
					++length;
				}
			}
			if (result < length) {
				result = length;
			}
		}
	}
	return result;
}

int gcd(int a, int b)
{
	do {
		int c = a % b;
		a = b;
		b = c;
	} while (b != 0);
	return a;
}
