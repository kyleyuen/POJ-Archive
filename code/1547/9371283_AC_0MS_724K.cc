#include <iostream>
#include <string>

using namespace std;

void solve(int students);

int main()
{
	int students;
	while (cin >> students) {
		if (students == -1) {
			break;
		}
		solve(students);
	}
	return 0;
}

void solve(int students)
{
	int a, b, c;
	cin >> a >> b >> c;
	int area = a * b * c;
	string name;
	cin >> name;

	int max_size = area;
	int min_size = area;
	string bully(name);
	string victim(name);
	for (int i = 1; i != students; ++i) {
		cin >> a >> b >> c >> name;
		area = a * b * c;
		if (max_size < area) {
			max_size = area;
			bully = name;
		}
		if (min_size > area) {
			min_size = area;
			victim = name;
		}
	}
	cout << bully << " took clay from " << victim << "." << endl;
}
