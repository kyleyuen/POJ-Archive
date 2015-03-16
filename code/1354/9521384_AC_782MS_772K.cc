#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string solve(int number);
string str_plus(const string& lhs, const string& rhs);
string str_multiply(const string& lhs, const string& rhs);

int main()
{
	int number;
	while (cin >> number) {
		if (number == -1) {
			break;
		}
		cout << "N=" << number << ":" << endl;
		cout << solve(number) << endl;
	}
	return 0;
}

string solve(int number)
{
	string result("2");
	stringstream ss;
	for (int i = 2; i < number; ++i) {
	    ss << i << endl;
	    string temp;
	    ss >> temp;
		result = str_multiply(result, temp);
	}
	return result;
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

	int i = lhs.size() - 1;
	int j = rhs.size() - 1;
	int index = result.size() - 1;
	while (i >= 0 && j >= 0) {
		result[index] = lhs[i] + rhs[j] - '0';
		--i;
		--j;
		--index;
	}

	for (int i = result.size() - 1; i != 0; --i) {
		if (result[i] > '9') {
			result[i] -= 10;
			++result[i - 1];
		}
	}
	if (result[0] > '9') {
		result[0] -= 10;
		result = "1" + result;
	}
	return result;
}

string str_multiply(const string& lhs, const string& rhs)
{
	string result("0");
	for (int i = rhs.size() - 1; i >= 0; --i) {
		string temp(lhs);
		for (int j = lhs.size() - 1; j >= 0; --j) {
			temp[j] = (temp[j] - '0') * (rhs[i] - '0');
		}
		for (int j = lhs.size() - 1; j > 0; --j) {
			temp[j - 1] += temp[j] / 10;
			temp[j] = temp[j] % 10 + '0';
		}
		if (temp[0] > 9) {
			int digit = temp[0] / 10 + '0';
			temp[0] = temp[0] % 10 + '0';
			temp = (char)digit + temp;
		}
		else {
			temp[0] += '0';
		}
		temp = temp + string(rhs.size() - i - 1, '0');
		result = str_plus(result, temp);
	}
	return result;
}
