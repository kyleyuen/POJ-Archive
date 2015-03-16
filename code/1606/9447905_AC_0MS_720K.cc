#include <iostream>

using namespace std;

void solve(int volumn_a, int volumn_b, int target);

int main()
{
	int volumn_a, volumn_b;
	int target;
	while (cin >> volumn_a >> volumn_b >> target) {
		solve(volumn_a, volumn_b, target);
	}
	return 0;
}

void solve(int volumn_a, int volumn_b, int target)
{
	int current_a = 0;
	int current_b = 0;
	while (current_b != target) {
		if (current_b == volumn_b) {
			current_b = 0;
			cout << "empty B" << endl;
		}
		else if (current_a == 0) {
			current_a = volumn_a;
			cout << "fill A" << endl;
		}
		else {
			current_b += current_a;
			current_a = 0;
			if (current_b > volumn_b) {
				current_a = current_b - volumn_b;
				current_b = volumn_b;
			}
			cout << "pour A B" << endl;
		}
	}
	cout << "success" << endl;
}
