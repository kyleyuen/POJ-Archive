#include <iostream>
#include <string>
#include <list>
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
	list<string> counter;
	string temp(origin);
	counter.push_back(temp);
	reverse(temp.begin(), temp.end());
	counter.push_back(temp);
	int length = origin.size();
	for (int i = 1; i != length; ++i) {
		for (int j = 0; j != i; ++j) {
			temp[j] = origin[j];
		}
		for (int j = i; j != length; ++j) {
			temp[j] = origin[length + i - j - 1];
		}
		counter.push_back(temp);

		for (int j = 0; j != i; ++j) {
			temp[j] = origin[i - j - 1];
		}
		for (int j = i; j != length; ++j) {
			temp[j] = origin[j];
		}
		counter.push_back(temp);

		for (int j = 0; j != i; ++j) {
			temp[j] = origin[i - j - 1];
		}
		for (int j = i; j != length; ++j) {
			temp[j] = origin[length + i - j - 1];
		}
		counter.push_back(temp);

		for (int j = 0; j != length - i; ++j) {
			temp[j] = origin[i + j];
		}
		for (int j = length - i; j != length; ++j) {
			temp[j] = origin[i + j - length];
		}
		counter.push_back(temp);

		for (int j = 0; j != length - i; ++j) {
			temp[j] = origin[i + j];
		}
		for (int j = length - i; j != length; ++j) {
			temp[j] = origin[length - j - 1];
		}
		counter.push_back(temp);

		for (int j = 0; j != length - i; ++j) {
			temp[j] = origin[length - j - 1];
		}
		for (int j = length - i; j != length; ++j) {
			temp[j] = origin[i + j - length];
		}
		counter.push_back(temp);
	}
	counter.sort();
	counter.unique();
	return counter.size();
}
