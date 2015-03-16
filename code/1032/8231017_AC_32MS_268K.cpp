#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;
void solve(int n);

int main()
{
	int n;
	while (cin >> n) {
		solve(n);
	}
	return 0;
}

void solve(int n)
{
	set<int> s;
	int sum = 0;
	int i = 2;
	while (sum + i <= n) {
		s.insert(i);
		sum += i;
		++i;
	}
	
	int p = n - sum;
	if (0 < p && p < i - 1) {
		s.insert(i);
		s.erase(i - p);
	}
	else if (p == i - 1) {
		s.erase(2);
		s.insert(i + 1);
	}
	for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;
}