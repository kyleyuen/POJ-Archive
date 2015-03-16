#include <iostream>
#include <vector>

using namespace std;

int solve(int n);

int main()
{
	int n;
	for (int i = 1; cin >> n; ++i) {
		if (n == 0) {
			break;
		}
		cout << "Set #" << i << endl;
		cout << "The minimum number of moves is " << solve(n) << "." << endl << endl;
	}
	return 0;
}

int solve(int n)
{
	vector<int> array(n);
	int sum = 0;
	for (int i = 0; i != n; ++i) {
		cin >> array[i];
		sum += array[i];
	}
	int average = sum / n;
	int result = 0;
	for (int i = 0; i != n; ++i) {
		if (array[i] > average) {
			result += array[i] - average;
		}
	}
	return result;
}
