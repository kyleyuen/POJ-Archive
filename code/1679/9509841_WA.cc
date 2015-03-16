#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Vertex {
	int parent;
	int rank;
};

struct Edge {
	int start;
	int end;
	int weight;
};

class Compare {
public:
	bool operator() (const Edge& lhs, const Edge& rhs) {
		return lhs.weight < rhs.weight;
	}
};

void solve();
int check(vector<Edge>& edges, int vertex_number, int index);
int kruskal_algorithm(vector<Edge>& edges, int vertex_number, vector<int>& reserve);
void make_set(vector<Vertex>& set);
void UNION(vector<Vertex>& set, int x, int y);
void link(vector<Vertex>& set, int x, int y);
int find_set(vector<Vertex>& set, int x);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		solve();
	}
	return 0;
}

void solve()
{
	int vertex_number;
	int edges_number;
	cin >> vertex_number >> edges_number;

	vector<Edge> edges(edges_number);
	for (int i = 0; i < edges_number; ++i) {
		cin >> edges[i].start >> edges[i].end >> edges[i].weight;
	}
	sort(edges.begin(), edges.end(), Compare());

	vector<int> reserve;
	int result = kruskal_algorithm(edges, vertex_number, reserve);
	for (vector<Edge>::size_type i = 0; i != reserve.size(); ++i) {
		if (check(edges, vertex_number, reserve[i]) == result) {
			cout << "Not Unique!" << endl;
			return;
		}
	}
	cout << result << endl;
}

int check(vector<Edge>& edges, int vertex_number, int index)
{
	vector<Vertex> graph(vertex_number + 1);
	make_set(graph);
	int result = 0;
	for (vector<Edge>::size_type i = 0; i != edges.size(); ++i) {
		if (i == index) {
			continue;
		}
		if (find_set(graph, edges[i].start) != find_set(graph, edges[i].end)) {
			result += edges[i].weight;
			UNION(graph, edges[i].start, edges[i].end);
		}
	}
	return result;
}

int kruskal_algorithm(vector<Edge>& edges, int vertex_number, vector<int>& reserve)
{
	vector<Vertex> graph(vertex_number + 1);
	make_set(graph);
	sort(edges.begin(), edges.end(), Compare());
	int result = 0;
	for (vector<Edge>::size_type i = 0; i != edges.size(); ++i) {
		if (find_set(graph, edges[i].start) != find_set(graph, edges[i].end)) {
			result += edges[i].weight;
			UNION(graph, edges[i].start, edges[i].end);
			reserve.push_back(i);
		}
	}
	return result;
}

void make_set(vector<Vertex>& set)
{
	for (vector<int>::size_type i = 0; i != set.size(); ++i) {
		set[i].parent = i;
		set[i].rank = 0;
	}
}

void UNION(vector<Vertex>& set, int x, int y)
{
	link(set, find_set(set, x), find_set(set, y));
}

void link(vector<Vertex>& set, int x, int y)
{
	if (set[x].rank > set[y].rank) {
		set[y].parent = x;
	}
	else {
		set[x].parent = y;
		if (set[x].rank == set[y].rank) {
			++set[y].rank;
		}
	}
}

int find_set(vector<Vertex>& set, int x)
{
	if (x != set[x].parent) {
		set[x].parent = find_set(set, set[x].parent);
	}
	return set[x].parent;
}
