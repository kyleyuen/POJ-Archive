#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Edge {
	Edge(int e, int w): end(e), weight(w) { }
	int end;
	int weight;
};

int solve(int points);
int prim_algorithm(vector< list<Edge> >& graph, int points);

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
	vector< list<Edge> > graph(points + 1);
	int routes;
	cin >> routes;
	for (int i = 0; i != routes; ++i) {
		int start, end;
		int distance;
		cin >> start >> end;
		cin >> distance;
		graph[start].push_back(Edge(end, distance));
		graph[end].push_back(Edge(start, distance));
	}

	return prim_algorithm(graph, points);
}

int prim_algorithm(vector< list<Edge> >& graph, int points)
{
	int result = 0;
	vector<bool> state(points + 1, false);
	state[1] = true;
	for (int i = 1; i != points; ++i) {
		int min = 10000;
		int index = -1;
		for (int j = 1; j <= points; ++j) {
			if (!state[j]) {
				continue;
			}
			for (list<Edge>::iterator iter = graph[j].begin(); iter != graph[j].end(); ++iter) {
				if (state[iter->end]) {
					continue;
				}
				if (min > iter->weight) {
					min = iter->weight;
					index = iter->end;
				}
			}
		}
		result += min;
		state[index] = true;
	}
	return result;
}
