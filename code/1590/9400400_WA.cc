#include <iostream>
#include <string>

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
	for (string::size_type i = 0; i != str.size() / 2; ++i) {
		switch (str[i]) {
		case 'A': if (str[str.size() - i - 1] != 'A') { return false; } break;
		case 'E': if (str[str.size() - i - 1] != '3') { return false; } break;
		case 'H': if (str[str.size() - i - 1] != 'H') { return false; } break;
		case 'I': if (str[str.size() - i - 1] != 'I') { return false; } break;
		case 'J': if (str[str.size() - i - 1] != 'L') { return false; } break;
		case 'L': if (str[str.size() - i - 1] != 'J') { return false; } break;
		case 'M': if (str[str.size() - i - 1] != 'M') { return false; } break;
		case 'O': if (str[str.size() - i - 1] != 'O') { return false; } break;
		case 'S': if (str[str.size() - i - 1] != '2') { return false; } break;
		case 'T': if (str[str.size() - i - 1] != 'T') { return false; } break;
		case 'U': if (str[str.size() - i - 1] != 'U') { return false; } break;
		case 'V': if (str[str.size() - i - 1] != 'V') { return false; } break;
		case 'W': if (str[str.size() - i - 1] != 'W') { return false; } break;
		case 'X': if (str[str.size() - i - 1] != 'X') { return false; } break;
		case 'Y': if (str[str.size() - i - 1] != 'Y') { return false; } break;
		case 'Z': if (str[str.size() - i - 1] != '5') { return false; } break;
		case '1': if (str[str.size() - i - 1] != '1') { return false; } break;
		case '2': if (str[str.size() - i - 1] != 'S') { return false; } break;
		case '3': if (str[str.size() - i - 1] != 'E') { return false; } break;
		case '5': if (str[str.size() - i - 1] != 'Z') { return false; } break;
		case '8': if (str[str.size() - i - 1] != '8') { return false; } break;
		default:
			return false;
		}
	}
	return true;
}
