#include <iostream>
#include <vector>

using namespace std;

struct Pearl {
	int price;
	int number;
};

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
	int kind;
	cin >> kind;
	vector<Pearl> pearls(kind + 1);
	for (int i = 1; i <= kind; ++i) {
		cin >> pearls[i].number >> pearls[i].price;
	}

	vector<int> dp(kind + 1);
	for (int i = 1; i <= kind; ++i) {
		int min = 10000000;
		int items = 0;
		for (int j = i; j >= 1; --j) {
			items += pearls[j].number;
			if (min > dp[j - 1] + (items + 10) * pearls[i].price) {
				min = dp[j - 1] + (items + 10) * pearls[i].price;
			}
		}
		dp[i] = min;
	}
	return dp[kind];
}
