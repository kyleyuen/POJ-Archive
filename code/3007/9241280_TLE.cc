#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solve(string& origin);
void insert_string(vector<string>& counter, string& str);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		string origin;
		cin >> origin;
		cout << solve(origin) << endl;
	}
	return 0;
}

int solve(string& origin)
{
	vector<string> counter;
	string temp(origin);
	insert_string(counter, temp);
	reverse(temp.begin(), temp.end());
	insert_string(counter, temp);
	int length = origin.size();
	for (int i = 1; i != length; ++i) {
		for (int j = 0; j != i; ++j) {
			temp[j] = origin[j];
		}
		for (int j = i; j != length; ++j) {
			temp[j] = origin[length + i - j - 1];
		}
		insert_string(counter, temp);

		for (int j = 0; j != i; ++j) {
			temp[j] = origin[i - j - 1];
		}
		for (int j = i; j != length; ++j) {
			temp[j] = origin[j];
		}
		insert_string(counter, temp);

		for (int j = 0; j != i; ++j) {
			temp[j] = origin[i - j - 1];
		}
		for (int j = i; j != length; ++j) {
			temp[j] = origin[length + i - j - 1];
		}
		insert_string(counter, temp);

		for (int j = 0; j != length - i; ++j) {
			temp[j] = origin[i + j];
		}
		for (int j = length - i; j != length; ++j) {
			temp[j] = origin[i + j - length];
		}
		insert_string(counter, temp);

		for (int j = 0; j != length - i; ++j) {
			temp[j] = origin[i + j];
		}
		for (int j = length - i; j != length; ++j) {
			temp[j] = origin[length - j - 1];
		}
		insert_string(counter, temp);

		for (int j = 0; j != length - i; ++j) {
			temp[j] = origin[length - j - 1];
		}
		for (int j = length - i; j != length; ++j) {
			temp[j] = origin[i + j - length];
		}
		insert_string(counter, temp);
	}
	return counter.size();
}

void insert_string(vector<string>& counter, string& str)
{
    for (vector<string>::iterator iter = counter.begin(); iter != counter.end(); ++iter) {
        if (*iter == str) {
            return;
        }
    }
    counter.push_back(str);
}
