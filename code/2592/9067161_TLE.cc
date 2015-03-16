#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.1415926;

void solve(int students_number);
double calculate(double percentage);

int main()
{
	int students_number;
	while (cin >> students_number) {
		if (students_number == 0) {
			break;
		}

		solve(students_number);
	}

	return 0;
}

void solve(int students_number)
{
	int score[151] = { 0 };
	for (int i = 0; i != students_number; ++i) {
		int temp;
		cin >> temp;
		++score[temp];
	}

	int query_number;
	cin >> query_number;
	for (int i = 0; i != query_number; ++i) {
		int temp;
		cin >> temp;
		int lower = 0;
		for (int i = 0; i != temp; ++i) {
			lower += score[i];
		}

		double x = calculate((double)lower / students_number);
		double point = 500 + 100 * x;
		if (point <= 100) {
			cout << 100 << endl;
		}
		else if (100 < point && point <= 501) {
			cout << (int)point << endl;
		}
		else if (501 < point && point <= 900) {
			if (point > (int)point) {
				cout << (int)point + 1 << endl;
			}
			else {
				cout << (int)point << endl;
			}
		}
		else {
			cout << 900 << endl;
		}
	}
	cout << endl;
}

double calculate(double percentage)
{
	double dx = 0.0002;
	double constant = 1.0 / sqrt(2 * PI);
	double x = 0, s = 0.5, t, m;
	if (percentage >= 0.5){
		while(x <= 5 && s <= percentage){
			m = x + dx / 2.0;
			t = exp(-(m*m)/2.0) * dx * constant;
			s=s+t;
			x += dx;
		}
	}
	else{
		while(x >= -5 && s >= percentage){
			m = x - dx / 2.0;
			t = exp(-(m*m)/2.0) * dx * constant;
			s -= t;
			x -= dx;
		}

	}
	return x;
}
