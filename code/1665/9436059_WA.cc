#include <iostream>
#include <iomanip>

using namespace std;

void solve(double diameter, int revolutions, int time);

const double PI = 3.1415927;
const int INCH_TO_MILE = 63360;
const int SECONDS_PER_HORE = 3600;

int main()
{
	double diameter;
	int revolutions, time;
	int counter = 1;
	while (cin >> diameter >> revolutions >> time) {
		if (revolutions == 0) {
			break;
		}
		cout << "Trip #" << counter << ": ";
		solve(diameter, revolutions, time);
		++counter;
	}
	return 0;
}

void solve(double diameter, int revolutions, int time)
{
	double distance = PI * diameter * revolutions / INCH_TO_MILE;
	double MPH = distance / time * SECONDS_PER_HORE;
	cout << fixed << setprecision(2) << distance << ' ' << MPH << endl;
}
