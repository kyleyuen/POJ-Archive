#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

void solve(int n);
void floyd_warshall(vector< vector<int> >& graph, int n);

int main()
{
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		solve(n);
	}
	return 0;
}

void solve(int n)
{
	vector< vector<int> > graph(n + 1, vector<int>(n + 1, MAX));
	for (int i = 1; i <= n; ++i) {
	    graph[i][i] = 0;

		int colleagues;
		cin >> colleagues;
		for (int j = 0; j != colleagues; ++j) {
			int target;
			int time;
			cin >> target >> time;
			graph[i][target] = time;
		}
	}

	floyd_warshall(graph, n);

	int time = MAX;
	int id = 0;
	for (int i = 1; i <= n; ++i) {
		int max = 0;
		for (int j = 1; j <= n; ++j) {
			if (graph[i][j] > max) {
                max = graph[i][j];
			}
		}
		if (time > max) {
			time = max;
			id = i;
		}
	}
	if (time == MAX) {
	    cout << "disjoint" << endl;
	}
	else {
		cout << id << ' ' << time << endl;
	}
}

void floyd_warshall(vector< vector<int> >& graph, int n)
{
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
}
