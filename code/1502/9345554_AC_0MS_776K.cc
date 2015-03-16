#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int solve(int n);
void floyd_warshall(vector< vector<int> >& graph, int n);

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}

int solve(int n)
{
	vector< vector<int> > graph(n, vector<int>(n));
	for (int i = 1; i != n; ++i) {
		for (int j = 0; j != i; ++j) {
			int length;
			if (scanf("%d", &length) != 0) {
				graph[i][j] = graph[j][i] = length;;
			}
			else {
				graph[i][j] = graph[j][i] = 1000000;
				scanf("x");
			}
		}
	}

	floyd_warshall(graph, n);
	int result = 0;
	for (int i = 0; i != n; ++i) {
		if (result < graph[0][i]) {
			result = graph[0][i];
		}
	}
	return result;
}

void floyd_warshall(vector< vector<int> >& graph, int n)
{
	for (int k = 0; k != n; ++k) {
		for (int i = 0; i != n; ++i) {
			for (int j = 0; j != n; ++j) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}
