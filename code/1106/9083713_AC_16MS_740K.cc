#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

int solve(Point center, double radius);
bool judge(Point& a, Point& b, Point& center);

int main()
{
	Point center;
	double radius;
	while (cin >> center.x >> center.y >> radius) {
		if (radius < 0) {
			break;
		}
		cout << solve(center, radius) << endl;
	}
	return 0;
}

int solve(Point center, double radius)
{
	int points_number;
	cin >> points_number;

	vector<Point> points;
	for (int i = 0; i != points_number; ++i) {
		Point temp;
		cin >> temp.x >> temp.y;
		if ((temp.x - center.x) * (temp.x - center.x) + (temp.y - center.y) * (temp.y - center.y) <= radius * radius) {
			points.push_back(temp);
		}
	}

	unsigned max = 0;
	for (vector<Point>::size_type i = 0; i != points.size(); ++i) {
		unsigned result = 0;
		for (vector<Point>::size_type j = 0; j != points.size(); ++j) {
			if (judge(points[i], points[j], center)) {
				++result;
			}
		}
		if (result * 2 < points.size()) {
			result = points.size() - result;
		}
		if (max < result) {
			max = result;
		}
	}
	return max;
}

bool judge(Point& a, Point& b, Point& center)
{
	return (center.x - b.x) * (a.y - b.y) - (center.y - b.y) * (a.x - b.x) <= 0;
}
