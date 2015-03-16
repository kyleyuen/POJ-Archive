#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solve(const vector<string>& code);
bool isPrefix(const string& lhs, const string& rhs);

int main()
{
	for (int i = 1; ; ++i) {
		if (cin.eof()) {
			break;
		}

		string binary_code;
		vector<string> code;
		while (cin >> binary_code) {
			if (binary_code == "9") {
				break;
			}
			code.push_back(binary_code);
		}
		cout << "Set " << i;
		if (solve(code)) {
			cout << " is immediately decodable" << endl;
		}
		else {
			cout << " is not immediately decodable" << endl;
		}
	}

	return 0;
}

bool solve(const vector<string>& code)
{
	for (vector<string>::size_type i = 0; i != code.size(); ++i) {
		for (vector<string>::size_type j = i + 1; j != code.size(); ++j) {
			if (isPrefix(code[i], code[j])) {
				return false;
			}
		}
	}
	return true;
}

bool isPrefix(const string& lhs, const string& rhs)
{
	if (lhs.size() < rhs.size()) {
        return rhs.compare(0, lhs.size(), lhs) == 0;
	}
	else {
        return lhs.compare(0, rhs.size(), rhs) == 0;
	}
}
