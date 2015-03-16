#include <iostream>
#include <vector>

using namespace std;

long long solve(int n);

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}

long long solve(int n)
{
	vector<long long> number(n + 1);
	number[1] = 1;
	number[2] = 2;
	for (int i = 3; i <= n; ++i) {
		if (i % 2 == 1) {
			number[i] = number[i - 1];
		}
		else {
			number[i] = number[i - 2] + number[i / 2];
			if (number[i] > 1000000000) {
                number[i] %= 1000000000;
			}
		}
	}
	return number[n];
}
