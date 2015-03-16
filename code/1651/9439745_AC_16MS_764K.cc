#include <iostream>
#include <vector>

using namespace std;

int solve(int n);
int matrix_chain(vector<int>& dimension);

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}

int solve(int n)
{
	vector<int> dimensions(n);
	for (int i = 0; i != n; ++i) {
		cin >> dimensions[i];
	}

	return matrix_chain(dimensions);
}

int matrix_chain(vector<int>& dimensions)
{
    int n = dimensions.size();
	vector< vector<int> > cost(n, vector<int>(n, 0x7FFFFFFF));
    for (int i = 1; i != n; ++i) {
        cost[i][i] = 0;
    }

    for (int l = 2; l != n; ++l) {
        for (int i = 1; i != n - l + 1; ++i) {
            int j = i + l - 1;
            for (int k = i; k != j; ++k) {
                int result = cost[i][k] + cost[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (result < cost[i][j]) {
                    cost[i][j] = result;
                }
            }
        }
    }
	return cost[1][dimensions.size() - 1];
}
