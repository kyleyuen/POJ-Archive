#include <iostream>

using namespace std;

int solve(int start, int end);
int calculate(int n);

int main()
{
	int start, end;
	while (cin >> start >> end) {
		cout << start << ' ' << end << ' ';
		if (start > end) {
			cout << solve(end, start) << endl;
		}
		else {
			cout << solve(start, end) << endl;
		}
	}
	return 0;
}

int solve(int start, int end)
{
	int result = 0;
	for (int i = start; i <= end; ++i) {
		int temp = calculate(i);
		if (result < temp) {
			result = temp;
		}
	}
	return result;
}

int calculate(int n)
{
	int counter = 1;
	while (n != 1) {
		if (n % 2 == 1) {
			n = n * 3 + 1;
		}
		else {
			n /= 2;
		}
		++counter;
	}
	return counter;
}
