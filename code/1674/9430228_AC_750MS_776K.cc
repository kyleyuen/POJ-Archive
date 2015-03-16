#include <iostream>
#include <vector>

using namespace std;

int solve();

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		cout << solve() << endl;
	}
	return 0;
}

int solve()
{
	int number;
	cin >> number;
	vector<int> array(number + 1);
	for (int i = 1; i <= number; ++i) {
		cin >> array[i];
	}

	int result = 0;
	for (int i = 1; i <= number; ++i) {
		if (i != array[i]) {
			int index = 0;
			for (int j = i; j <= number; ++j) {
                if (array[j] == i) {
                    index = j;
                    break;
                }
			}
			array[index] = array[i];
			array[i] = i;
			++result;
		}
	}
	return result;
}
