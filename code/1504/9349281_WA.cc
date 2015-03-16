#include <iostream>
#include <string>

using namespace std;

void solve();
string str_plus(const string& lhs, const string& rhs);
void reverse(string& str);
void erase_prefix_zero(string& str);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		solve();
	}
	return 0;
}

void solve()
{
	string lhs, rhs;
	cin >> lhs >> rhs;
	string result = str_plus(lhs, rhs);
	reverse(result);
	cout << result << endl;
}

string str_plus(const string& lhs, const string& rhs)
{
	string result;
	if (lhs.size() > rhs.size()) {
		result = lhs;
	}
	else {
		result = rhs;
	}

	int size = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
	for (int i = 0; i != size; ++i) {
		result[i] = lhs[i] + rhs[i] - '0';
	}
	for (int i = 0; i != size - 1; ++i) {
		if (result[i] > '9') {
			result[i] -= 10;
			++result[i + 1];
		}
	}
	if (result[result.size() - 1] > '9') {
		result[result.size() - 1] -= 10;
		result = result + "1";
	}
	return result;
}

void reverse(string& str)
{
	for (string::size_type i = 0; i != str.size(); ++i) {
		char temp = str[i];
		str[i] = str[str.size() - i - 1];
		str[str.size() - i - 1] = temp;
	}
	erase_prefix_zero(str);
}

void erase_prefix_zero(string& str)
{
    string::iterator iter = str.begin();
	while (iter != str.end()) {
		if (*iter != '0') {
			break;
		}
		++iter;
	}
	str.erase(str.begin(), iter);
}
