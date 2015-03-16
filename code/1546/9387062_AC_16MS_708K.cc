#include <iostream>
#include <iomanip>
#include <stack>
#include <string>

using namespace std;

void solve(string& str, int base, int target);
int get_value(string& str, int base);

int main()
{
	string str;
	int base, target;
	while (cin >> str >> base >> target) {
		solve(str, base, target);
	}
	return 0;
}

void solve(string& str, int base, int target)
{
	int value = get_value(str, base);
	stack<char> st;
	while (value != 0) {
		st.push(value % target);
		value /= target;
	}

	string result;
	while (!st.empty()) {
		char c = st.top();
		switch (st.top()) {
		case 0: case 1: case 2: case 3: case 4:
		case 5: case 6: case 7: case 8: case 9:
			c += '0';
			break;
		case 10: case 11: case 12: case 13: case 14: case 15:
			c += 55;
			break;
		}
		result.push_back(c);
		st.pop();
	}
	if (result.size() > 7) {
        cout << setw(7) << "ERROR" << endl;
	}
	else {
        cout << setw(7) << result << endl;
	}
}

int get_value(string& str, int base)
{
	for (string::size_type i = 0; i != str.size(); ++i) {
		if (isdigit(str[i])) {
			str[i] -= 48;
		}
		else if (isupper(str[i])) {
			str[i] -= 55;
		}
	}
	int result = 0;
	for (string::size_type i = 0; i != str.size(); ++i) {
		result = result * base + str[i];
	}
	return result;
}
