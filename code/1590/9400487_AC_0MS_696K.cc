#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve(const string& line);
bool isPalindrome(const string& str);
bool isMirrored(const string& str);

int main()
{
	string line;
	while (cin >> line) {
		solve(line);
	}
	return 0;
}

void solve(const string& line)
{
	bool palindrome = isPalindrome(line);
	bool mirrored = isMirrored(line);

	cout << line;
	if (palindrome) {
		if (mirrored) {
			cout << " -- is a mirrored palindrome." << endl;
		}
		else {
			cout << " -- is a regular palindrome." << endl;
		}
	}
	else {
		if (mirrored) {
			cout << " -- is a mirrored string." << endl;
		}
		else {
			cout << " -- is not a palindrome." << endl;
		}
	}
	cout << endl;
}

bool isPalindrome(const string& str)
{
	for (string::size_type i = 0; i != str.size() / 2; ++i) {
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

bool isMirrored(const string& str)
{
	string temp(str);
	for (string::size_type i = 0; i != temp.size(); ++i) {
		switch (temp[i]) {
		case 'A': case 'H': case 'I': case 'M': case 'O':
		case 'T': case 'U': case 'V': case 'W': case 'X':
		case 'Y': case '1': case '8': break;
		case 'E': temp[i] = '3'; break;
		case 'J': temp[i] = 'L'; break;
		case 'L': temp[i] = 'J'; break;
		case 'S': temp[i] = '2'; break;
		case 'Z': temp[i] = '5'; break;
		case '2': temp[i] = 'S'; break;
		case '3': temp[i] = 'E'; break;
		case '5': temp[i] = 'Z'; break;
		default:
			return false;
		}
	}
	reverse(temp.begin(), temp.end());
	return str == temp;
}
