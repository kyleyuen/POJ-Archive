#include <iostream>
#include <cstdio>

using namespace std;

void solve();

int main()
{
	int total_cases;
	cin >> total_cases;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	for (int i = 1; i <= total_cases; ++i) {
		solve();
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

void solve()
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x3 >> y3 >> x4 >> y4;
	x1 -= x2;
	y1 -= y2;
	x3 -= x4;
	y3 -= y4;
	double t = x1 * y3 - y1 * x3;
	if (t == 0) {
		x2 -= x4;
		y2 -= y4;
		if (x2 * y3 == x3 * y2) {
			cout << "LINE" << endl;
		}
		else {
			cout << "NONE" << endl;
		}
	}
	else {
		printf("POINT %.2f %.2f\n", (x1*y2*x3-y1*x2*x3+x1*y3*x4-x1*x3*y4) / t, (x1*y2*y3-y1*x2*y3+y1*y3*x4-y1*x3*y4) / t);
	}
}
