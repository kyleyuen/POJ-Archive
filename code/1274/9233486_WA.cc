#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solve(int cows, int stalls);
bool find_argumenting_path(vector< vector<bool> >& graph, int start, int end, vector<int>& path);

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
	vector< vector<bool> > graph(cows + stalls + 2, vector<bool>(cows + stalls + 2, false));
	int start = 0;
	int end = cows + stalls + 1;
	for (int i = 1; i <= cows; ++i) {
		graph[start][i] = true;
	}
	for (int i = cows + 1; i <= cows + stalls; ++i) {
		graph[i][end] = true;
	}
	for (int i = 1; i <= cows; ++i) {
		int production;
		cin >> production;
		for (int j = 0; j != production; ++j) {
			int stall;
			cin >> stall;
			graph[i][cows + stall] = true;
		}
	}

	int result = 0;
	while (true) {
        vector<int> path(cows + stalls + 2, -1);
        if (find_argumenting_path(graph, start, end, path)) {
            ++result;
        }
        else {
            break;
        }
	}
	return result;
}

bool find_argumenting_path(vector< vector<bool> >& graph, int start, int end, vector<int>& path)
{
	vector<bool> state(path.size(), true);
	deque<int> queue;
	queue.push_back(start);
	state[start] = false;
	while (!queue.empty()) {
		int vertex = queue.front();
		queue.pop_front();
		for (int i = start; i <= end; ++i) {
			if (state[i] && graph[vertex][i]) {
				path[i] = vertex;
				queue.push_back(i);
				state[i] = false;
			}
		}
	}

	if (path[end] != -1) {
	    int vertex = end;
        while (vertex != start) {
            graph[path[vertex]][vertex] = false;
            vertex = path[vertex];
        }
        return true;
	}
	return false;
}
