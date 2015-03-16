#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

int solve(int n);

int main()
{
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << solve(n) << endl;
	}
	return 0;
}

int solve(int n)
{
	vector<Point> points(n);
	for (int i = 0; i != n; ++i) {
		cin >> points[i].x >> points[i].y;
	}

	int max = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int result = 2;
			for (int k = j + 1; k < n; ++k) {
				if ((points[k].y - points[i].y) * (points[j].x - points[i].x) == (points[k].x - points[i].x) * (points[j].y - points[i].y)) {
					++result;
				}
			}
			if (max < result) {
				max = result;
			}
		}
	}
	return max;
}
