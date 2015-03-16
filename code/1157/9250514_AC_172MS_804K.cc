#include <iostream>
#include <vector>

using namespace std;

const int NEGATIVE = - 10000;

int solve(int flowers, int vases);

int main()
{
	int flowers, vases;
	cin >> flowers >> vases;
	cout << solve(flowers, vases) << endl;
	return 0;
}

int solve(int flowers, int vases)
{
	vector< vector<int> > array(flowers + 1, vector<int>(vases + 1));
	for (int i = 1; i <= flowers; ++i) {
		for (int j = 1; j <= vases; ++j) {
			cin >> array[i][j];
		}
	}

	vector< vector<int> > dp(flowers + 1, vector<int>(vases + 1, NEGATIVE));
	for (int i = 0; i <= vases; ++i) {
        dp[0][i] = 0;
    }
	for (int i = 1; i <= flowers; ++i) {
		for (int j = i; j <= vases - flowers + i; ++j) {
		    for (int k = i; k <= j; ++k) {
                if (dp[i][j] < dp[i - 1][k - 1] + array[i][k]) {
                    dp[i][j] = dp[i - 1][k - 1] + array[i][k];
                }
		    }
		}
	}
	return dp[flowers][vases];
}
