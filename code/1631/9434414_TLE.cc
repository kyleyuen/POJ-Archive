#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int rank;
	int maximum;
};

int solve(int number);
int LIS(vector<int>& array);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		int number;
		cin >> number;
		cout << solve(number) << endl;
	}
	return 0;
}

int solve(int number)
{
	vector<int> array(number + 1);
	for (int i = 1; i <= number; ++i) {
		cin >> array[i];
	}

	return LIS(array);
}

int LIS(vector<int>& array)
{
	vector<int> dp(array.size());
	dp[1] = array[1];
	int length = 1;
	for (vector<int>::size_type i = 2; i != dp.size(); ++i) {
		int left = 1;
		int right = length;
		if (dp[length] <= array[i]) {
			++length;
			dp[length] = array[i];
			continue;
		}

		while (left <= right) {
			int middle = (left + right) / 2;
			if (dp[middle] <= array[i]) {
				left = middle + 1;
			}
			else {
				right = middle - 1;
			}
		}
		dp[left] = array[i];
		if (length < left) {
			++length;
		}
	}
	return length;
}
