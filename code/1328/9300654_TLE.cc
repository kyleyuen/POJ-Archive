#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Range {
	double left;
	double right;
};

class Compare {
public:
	bool operator() (const Range& lhs, const Range& rhs) {
		return lhs.left < rhs.left;
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
	vector<Range> range(islands);
	bool judge = true;

	for (int i = 0; i != islands; ++i) {
		double x, y;
		cin >> x >> y;
		if (radius < y) {
            judge = false;
            continue;
		}
        range[i].left = x - sqrt(radius * radius - y * y);
        range[i].right = x + sqrt(radius * radius - y * y);
	}

    if (!judge) {
		return -1;
	}
	sort(range.begin(), range.end(), Compare());

	int result = 1;
	double end = range[0].right;
	for (int i = 1; i != islands; ++i) {
		if (end < range[i].left) {
		    end = range[i].right;
		    ++result;
		}
		else if (end > range[i].right){
            end = range[i].right;
		}
	}
	return result;
}
