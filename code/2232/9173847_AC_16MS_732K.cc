#include <iostream>

using namespace std;

int solve(int n);

int main()
{
	int n;
	while (cin >> n) {
		cout << solve(n) << endl;
	}
	return 0;
}

int solve(int n)
{
	int stone = 0;
	int forfex = 0;
	int cloth = 0;
	for (int i = 0; i != n; ++i) {
		char c;
		cin >> c;
		if (c == 'S') {
			++stone;
		}
		else if (c == 'F') {
			++forfex;
		}
		else if (c == 'C') {
			++cloth;
		}
	}
	
	if (stone == 0 && forfex != 0 && cloth != 0) {
		return (forfex > cloth) ? forfex : cloth;
	}
	if (stone != 0 && forfex == 0 && cloth != 0) {
		return (stone > cloth) ? stone : cloth;
	}
	if (stone != 0 && forfex != 0 && cloth == 0) {
		return (stone > forfex) ? stone : forfex;
	}
	return n;
}