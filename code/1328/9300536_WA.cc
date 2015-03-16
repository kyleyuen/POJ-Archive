#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
};

class Compare {
public:
	bool operator() (const Point& lhs, const Point& rhs) {
		return lhs.x < rhs.x;
	}
};

int solve(int islands, int radius);

int main()
{
	for (int i = 1; ; ++i) {
		int islands, radius;
		cin >> islands >> radius;
		if (islands == 0 && radius == 0) {
			break;
		}
		cout << "Case " << i << ": " << solve(islands, radius) << endl;
	}
	return 0;
}

int solve(int islands, int radius)
{
	vector<Point> position(islands);
	vector<Point> range(islands);
	bool judge = true;

	for (int i = 0; i != islands; ++i) {
		cin >> position[i].x >> position[i].y;
		if (radius < position[i].y) {
            judge = false;
            continue;
		}
        range[i].x = position[i].x - sqrt(radius * radius - position[i].y * position[i].y);
        range[i].y = position[i].x + sqrt(radius * radius - position[i].y * position[i].y);
	}

    if (!judge) {
		return -1;
	}
	sort(range.begin(), range.end(), Compare());

	int result = 1;
	int end = range[0].y;
	for (int i = 1; i != islands; ++i) {
		if (end < range[i].x) {
		    end = range[i].y;
		    ++result;
		}
		else if (end > range[i].y){
            end = range[i].y;
		}
	}
	return result;
}
