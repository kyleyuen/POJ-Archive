#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve();

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
	string start, end;
	cin >> start >> end;
	int x = abs(end[0] - start[0]);
	int y = abs(end[1] - start[1]);

	if (x == 0 && y == 0) {
		cout << "0 0 0 0" << endl;
		return;
	}
	
	int king = x > y ? x : y;
	int queen = (x == 0 || y == 0 || x == y) ? 1 : 2;
	int rook = (x == 0 || y == 0) ? 1: 2;
	int bishop;
	if (x == y) {
		bishop = 1;
	}
	else if ((x + y) % 2 == 0) {
		bishop = 2;
	}
	else {
		bishop = 0;
	}

	cout << king << ' ' << queen << ' ' << rook << ' ';
	if (bishop) {
		cout << bishop << endl;
	}
	else {
		cout << "Inf" << endl;
	}
}
