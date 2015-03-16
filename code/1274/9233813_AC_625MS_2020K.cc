#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(int cows, int stalls);
int bipartite_matching(vector< vector<int> >& graph, int start, int end);
bool find_argumenting_path(vector< vector<int> >& graph, int start, int end, vector<int>& path);

int main()
{
	int cows, stalls;
	while (cin >> cows >> stalls) {
		cout << solve(cows, stalls) << endl;
	}
	return 0;
}

int solve(int cows, int stalls)
{
	vector< vector<int> > graph(cows + stalls + 2, vector<int>(cows + stalls + 2, 0));
	int start = 0;
	int end = cows + stalls + 1;
	for (int i = 1; i <= cows; ++i) {
		graph[start][i] = 1;
	}
	for (int i = cows + 1; i <= cows + stalls; ++i) {
		graph[i][end] = 1;
	}
	for (int i = 1; i <= cows; ++i) {
		int production;
		cin >> production;
		for (int j = 0; j != production; ++j) {
			int stall;
			cin >> stall;
			graph[i][cows + stall] = 1;
		}
	}

	return bipartite_matching(graph, start, end);
}

int bipartite_matching(vector< vector<int> >& graph, int start, int end)
{
	vector< vector<int> > flow(end + 1, vector<int>(end + 1, 0));
	vector<int> path(end + 1, -1);
	while (find_argumenting_path(graph, start, end, path)) {
		int vertex = end;
		while (vertex != start) {
			graph[path[vertex]][vertex] -= 1;
			graph[vertex][path[vertex]] += 1;
			flow[path[vertex]][vertex] += 1;
			flow[vertex][path[vertex]] = -flow[path[vertex]][vertex];
			vertex = path[vertex];
		}
		for (int i = 1; i <= end; ++i) {
			path[i] = -1;
		}
	}

	int result = 0;
	for (int i = 1; i <= end; ++i) {
		result += flow[start][i];
	}
	return result;
}

bool find_argumenting_path(vector< vector<int> >& graph, int start, int end, vector<int>& path)
{
	vector<bool> state(end + 1, true);
	deque<int> queue;
	queue.push_back(start);
	state[start] = false;
	while (!queue.empty()) {
		int vertex = queue.front();
		queue.pop_front();
		for (int i = start; i <= end; ++i) {
			if (state[i] && graph[vertex][i] > 0) {
				path[i] = vertex;
				queue.push_back(i);
				state[i] = false;
			}
		}
	}
	return path[end] != -1;
}
