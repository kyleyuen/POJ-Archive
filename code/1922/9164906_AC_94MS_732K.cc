#include <iostream>

using namespace std;

int solve(int riders);

int main()
{
	int riders;
	while (cin >> riders) {
		if (riders == 0) {
			break;
		}
		cout << solve(riders) << endl;
	}
	return 0;
}

int solve(int riders)
{
	int result = 1000000;
	for (int i = 0; i != riders; ++i) {
		int speed, time;
		cin >> speed >> time;
		if (time < 0) {
            continue;
		}

		double temp = time + 4500 / (speed * 10.0 / 36.0);
		if (temp - (int)temp > 0) {
			temp = (int)temp + 1;
		}
		if (result > temp) {
			result = temp;
		}
	}
	return result;
}
