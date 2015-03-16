#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100000000;

int solve(int ditchs, int ponds);
int edmonds_karp(vector< vector<int> >& graph, int start, int end);
bool find_argumenting_path(vector< vector<int> >& graph, int start, int end, vector<int>& path);

int main()
{
	int ditchs, ponds;
	while (cin >> ditchs >> ponds) {
		cout << solve(ditchs, ponds) << endl;
	}
	return 0;
}

int solve(int ditchs, int ponds)
{
	vector< vector<int> > graph(ponds + 1, vector<int>(ponds + 1, 0));
	for (int i = 0; i != ditchs; ++i) {
		int start, end, flow;
		cin >> start >> end >> flow;
		graph[start][end] += flow;
	}

	return edmonds_karp(graph, 1, ponds);
}

int edmonds_karp(vector< vector<int> >& graph, int start, int end)
{
	vector< vector<int> > flow(end + 1, vector<int>(end + 1, 0));
	vector<int> path(end + 1, 0);
	while (find_argumenting_path(graph, start, end, path)) {
		int min = MAX;
		int vertex = end;
		while (vertex != start) {
			if (min > graph[path[vertex]][vertex]) {
				min = graph[path[vertex]][vertex];
			}
			vertex = path[vertex];
		}
		vertex = end;
		while (vertex != start) {
			graph[path[vertex]][vertex] -= min;
			graph[vertex][path[vertex]] += min;
			flow[path[vertex]][vertex] += min;
			flow[vertex][path[vertex]] = -flow[path[vertex]][vertex];
			vertex= path[vertex];
		}
		for (int i = 1; i <= end; ++i) {
			path[i] = 0;
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
	vector<bool> state(path.size(), true);
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
	return path[end] != 0;
}
