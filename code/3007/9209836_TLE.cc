#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int solve(string& origin);

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
	set<string> counter;
	string temp(origin);
	counter.insert(temp);
	reverse(temp.begin(), temp.end());
	counter.insert(temp);
	int length = origin.size();
	for (int i = 1; i != length; ++i) {
		for (int j = 0; j != i; ++j) {
			temp[j] = origin[j];
		}
		for (int j = i; j != length; ++j) {
			temp[j] = origin[length + i - j - 1];
		}
		counter.insert(temp);

		for (int j = 0; j != i; ++j) {
			temp[j] = origin[i - j - 1];
		}
		for (int j = i; j != length; ++j) {
			temp[j] = origin[j];
		}
		counter.insert(temp);

		for (int j = 0; j != i; ++j) {
			temp[j] = origin[i - j - 1];
		}
		for (int j = i; j != length; ++j) {
			temp[j] = origin[length + i - j - 1];
		}
		counter.insert(temp);

		for (int j = 0; j != length - i; ++j) {
			temp[j] = origin[i + j];
		}
		for (int j = length - i; j != length; ++j) {
			temp[j] = origin[i + j - length];
		}
		counter.insert(temp);

		for (int j = 0; j != length - i; ++j) {
			temp[j] = origin[i + j];
		}
		for (int j = length - i; j != length; ++j) {
			temp[j] = origin[length - j - 1];
		}
		counter.insert(temp);

		for (int j = 0; j != length - i; ++j) {
			temp[j] = origin[length - j - 1];
		}
		for (int j = length - i; j != length; ++j) {
			temp[j] = origin[i + j - length];
		}
		counter.insert(temp);
	}
	return counter.size();
}
