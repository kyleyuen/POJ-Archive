#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(int number);
string reverse_string(const string& str);
bool find_string(vector<string>& words, const string& base, const string& reverse);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		int number;
		cin >> number;
		cout << solve(number) << endl;
	}
	return 0;
}

int solve(int number)
{
	vector<string> words(number);
	for (int i = 0; i != number; ++i) {
		cin >> words[i];
	}

	int result = 0;
	for (int i = 0; i != number; ++i) {
		for (int str_len = 1; str_len <= words[i].size(); ++str_len) {
			for (int str_start = 0; str_start <= words[i].size() - str_len; ++str_start) {
				string base(words[i].substr(str_start, str_len));
				string reverse = reverse_string(base);
				if (find_string(words, base, reverse)) {
					if (result < str_len) {
                        result = str_len;
					}
					break;
				}
			}
		}
	}
	return result;
}

string reverse_string(const string& str)
{
    string temp(str);
	for (string::size_type i = 0; i != str.size(); ++i) {
	    temp[i] = str[str.size() - i - 1];
	}
	return temp;
}

bool find_string(vector<string>& words, const string& base, const string& reverse)
{
	for (vector<string>::size_type i = 0; i != words.size(); ++i) {
		if ((words[i].find(base) == string::npos) && (words[i].find(reverse) == string::npos)) {
			return false;
		}
	}
	return true;
}
