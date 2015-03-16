#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.1415926;

double solve();

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		cout << "Scenario #" << i << ":" << endl;
		cout << fixed << setprecision(3) << solve() << endl;
		cout << endl;
	}
	return 0;
}

double solve()
{
	double radius;
	int circles;
	cin >> radius >> circles;
	return radius * sin(PI / circles) / (1 + sin(PI / circles));
}
