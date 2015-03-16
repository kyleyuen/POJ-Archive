#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

struct Edge {
	Edge(int e, int w): end(e), weight(w) { }
	int end;
	int weight;
};

int solve();
void reverse(vector< list<Edge> >& graph);
int spfa(vector< list<Edge> >& graph);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		cout << solve() << endl;
	}
	return 0;
}

int solve()
{
	int stops, lines;
	cin >> stops >> lines;

	vector< list<Edge> > graph(stops + 1);
	for (int i = 0; i != lines; ++i) {
		int start, end, weight;
		cin >> start >> end >> weight;
		graph[start].push_back(Edge(end, weight));
	}

	int result = 0;
	result += spfa(graph);
	reverse(graph);
	result += spfa(graph);
	return result;
}

void reverse(vector< list<Edge> >& graph)
{
	vector< list<Edge> > temp(graph.size());
	for (vector< list<Edge> >::size_type i = 1; i != graph.size(); ++i) {
		for (list<Edge>::iterator iter = graph[i].begin(); iter != graph[i].end(); ++iter) {
			temp[iter->end].push_back(Edge(i, iter->weight));
		}
	}
	graph = temp;
}

int spfa(vector< list<Edge> >& graph)
{
	vector<int> distance(graph.size(), 1000000000);
	distance[1] = 0;
	deque<int> queue;
	queue.push_back(1);
	while (!queue.empty()) {
		int vertex = queue.front();
		queue.pop_front();
		for (list<Edge>::iterator iter = graph[vertex].begin(); iter != graph[vertex].end(); ++iter) {
			int temp = distance[iter->end];
			if (distance[iter->end] > distance[vertex] + iter->weight) {
				distance[iter->end] = distance[vertex] + iter->weight;
			}
			if (temp != distance[iter->end]) {
				queue.push_back(iter->end);
			}
		}
	}

	int result = 0;
	for (vector<int>::size_type i = 1; i != distance.size(); ++i) {
		result += distance[i];
	}
	return result;
}
