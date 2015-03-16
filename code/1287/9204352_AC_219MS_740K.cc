#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

int solve(int points);
int prim_algorithm(vector< vector<int> >& graph, int points);

int main()
{
	int points;
	while (cin >> points) {
		if (points == 0) {
			break;
		}
		cout << solve(points) << endl;
	}
	return 0;
}

int solve(int points)
{
	vector< vector<int> > graph(points + 1, vector<int>(points + 1, MAX));
	int routes;
	cin >> routes;
	for (int i = 0; i != routes; ++i) {
		int start, end;
		int distance;
		cin >> start >> end;
		cin >> distance;
		if (graph[start][end] > distance) {
			graph[start][end] = distance;
			graph[end][start] = distance;
		}
	}

	return prim_algorithm(graph, points);
}

int prim_algorithm(vector< vector<int> >& graph, int points)
{
	int result = 0;
	vector<bool> state(points + 1, false);
	state[1] = true;
	for (int i = 1; i != points; ++i) {
		int min = 1000000;
		int index = -1;
		for (int j = 1; j <= points; ++j) {
			if (!state[j]) {
				continue;
			}
			for (int k = 1; k <= points; ++k) {
				if (state[k]) {
					continue;
				}
				if (graph[j][k] != MAX && min > graph[j][k]) {
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
