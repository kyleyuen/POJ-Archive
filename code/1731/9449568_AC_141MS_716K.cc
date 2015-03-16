#include <iostream>
#include <algorithm>

using namespace std;

void solve(string& str);

int main()
{
	string str;
	cin >> str;
	solve(str);
	return 0;
}

void solve(string& str)
{
	sort(str.begin(), str.end());
	do {
		cout << str << endl;
	} while (next_permutation(str.begin(), str.end()));
}
