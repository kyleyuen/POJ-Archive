#include <iostream>
#include <vector>

using namespace std;

int solve(int farms);
int prim_algorithm(vector< vector<int> >& graph, int farms);

int main()
{
	int farms;
	while (cin >> farms) {
		cout << solve(farms) << endl;
	}
	return 0;
}

int solve(int farms)
{
	vector< vector<int> > graph(farms, vector<int>(farms));
	for (int i = 0; i != farms; ++i) {
		for (int j = 0; j != farms; ++j) {
			cin >> graph[i][j];
		}
	}

	return prim_algorithm(graph, farms);
}

int prim_algorithm(vector< vector<int> >& graph, int farms)
{
	int result = 0;
	vector<bool> state(farms, false);
	state[0] = true;
	for (int i = 1; i != farms; ++i) {
		int min = 1000000;
		int index = -1;
		for (int j = 0; j != farms; ++j) {
			if (!state[j]) {
				continue;
			}
			for (int k = 0; k != farms; ++k) {
				if (state[k]) {
					continue;
				}
				if (graph[j][k] != 0 && min > graph[j][k]) {
					min = graph[j][k];
					index = k;
				}
			}
		}
		result += min;
		state[index] = true;
	}
	return result;
}
