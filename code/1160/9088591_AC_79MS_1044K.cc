#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10000000;

int solve(int villages_number, int offices_number);

int main()
{
	int villages_number;
	int offices_number;
	cin >> villages_number >> offices_number;
	cout << solve(villages_number, offices_number) << endl;
	return 0;
}

int solve(int villages_number, int offices_number)
{
	vector<int> villages(villages_number + 1);
	for (int i = 1; i <= villages_number; ++i) {
		cin >> villages[i];
	}

	vector< vector<int> > cost(villages_number + 1, vector<int>(villages_number + 1, 0));
	for (int i = 1; i != villages_number; ++i) {
		for (int j = i + 1; j <= villages_number; ++j) {
            int middle = (i + j) / 2;
            for (int k = i; k <= middle; k++)
                cost[i][j] += villages[middle] - villages[k];
            for (int k = middle + 1; k <= j; k++)
                cost[i][j] += villages[k] - villages[middle];
		}
	}

	vector< vector<int> > distance(offices_number + 1, vector<int>(villages_number + 1, MAX));
	for (int i = 1; i <= villages_number; ++i) {
        distance[1][i] = cost[1][i];
	}
	for (int i = 2; i <= offices_number; ++i) {
		for (int j = i; j <= villages_number; ++j) {
			for (int k = 1; k != j; ++k) {
				if (distance[i][j] > distance[i - 1][k] + cost[k + 1][j]) {
					distance[i][j] = distance[i - 1][k] + cost[k + 1][j];
				}
			}
		}
	}
	return distance[offices_number][villages_number];
}
