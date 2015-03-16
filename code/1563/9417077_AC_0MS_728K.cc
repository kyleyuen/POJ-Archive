#include <iostream>

using namespace std;

void solve(int height, int speed, int slide_down, int factor);

int main()
{
	int height;
	int speed;
	int slide_down;
	int factor;
	while (cin >> height >> speed >> slide_down >> factor) {
		if (height == 0) {
			break;
		}
		solve(height, speed, slide_down, factor);
	}
	return 0;
}

void solve(int height, int speed, int slide_down, int factor)
{
	double current_height = 0;
	double current_speed = speed;
	double speed_lost = double(speed) * factor / 100;
	int days = 1;
	while (current_height >= 0) {
		if (current_speed > 0) {
			current_height += current_speed;
		}
		if (current_height > height) {
			cout << "success on day " << days << endl;
			return;
		}

        current_height -= slide_down;
        current_speed -= speed_lost;
        ++days;
	}
	cout << "failure on day " << days - 1 << endl;
}
