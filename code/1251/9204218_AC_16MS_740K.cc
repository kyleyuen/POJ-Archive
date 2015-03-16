#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Edge {
	Edge(int e, int w): end(e), weight(w) { }
	int end;
	int weight;
};

int solve(int villages);
int prim_algorithm(vector< list<Edge> >& graph, int villages);

int main()
{
	int villages;
	while (cin >> villages) {
		if (villages == 0) {
			break;
		}
		cout << solve(villages) << endl;
	}
	return 0;
}

int solve(int villages)
{
	vector< list<Edge> > graph(villages);
	for (int i = 1; i != villages; ++i) {
		char start;
		cin >> start;
		int roads;
		cin >> roads;
		for (int j = 0; j != roads; ++j) {
			char end;
			cin >> end;
			int distance;
			cin >> distance;
			graph[start - 'A'].push_back(Edge(end - 'A', distance));
			graph[end - 'A'].push_back(Edge(start - 'A', distance));
		}
	}

	return prim_algorithm(graph, villages);
}

int prim_algorithm(vector< list<Edge> >& graph, int villages)
{
	int result = 0;
	vector<bool> state(villages, false);
	state[0] = true;
	for (int i = 1; i != villages; ++i) {
		int min = 10000;
		int index = -1;
		for (int j = 0; j != villages; ++j) {
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
