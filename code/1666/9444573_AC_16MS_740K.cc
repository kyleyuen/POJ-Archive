#include <iostream>
#include <vector>

using namespace std;

void solve(int student_number);
bool check(vector<int>& students);
void update(vector<int>& students);

int main()
{
	int student_number;
	while (cin >> student_number) {
		if (student_number == 0) {
			break;
		}
		solve(student_number);
	}
	return 0;
}

void solve(int student_number)
{
	vector<int> students(student_number);
	for (int i = 0; i != student_number; ++i) {
		cin >> students[i];
	}

	int turns = 0;
	while (check(students)) {
		update(students);
		++turns;
	}
	cout << turns << ' ' << students[0] << endl;
}

bool check(vector<int>& students)
{
	int temp = students[0];
	for (vector<int>::size_type i = 1; i != students.size(); ++i) {
		if (temp != students[i]) {
			return true;
		}
	}
	return false;
}

void update(vector<int>& students)
{
	vector<int> array(students);
	int last_student = students.size() - 1;
	for (int i = 0; i < last_student; ++i) {
		students[i] /= 2;
		students[i] += array[i + 1] / 2;
		if (students[i] % 2 == 1) {
			++students[i];
		}
	}
	students[last_student] /= 2;
	students[last_student] += array[0] / 2;
	if (students[last_student] % 2 == 1) {
		++students[last_student];
	}
}
