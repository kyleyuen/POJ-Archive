#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX = 100000;

int solve(int towns_number, int regions_number);
void towns_to_edges(vector< vector<int> >& towns, vector< vector<int> >& edges);
void edges_to_graph(vector< vector<int> >& edges, vector< vector<int> >& graph);
int calculate_minimum(vector< vector<int> >& graph, set<int>& result);
void floyd_warshall(vector< vector<int> >& graph, int n);

int main()
{
	int towns_number;
	int regions_number;
	cin >> towns_number >> regions_number;
	cout << solve(towns_number, regions_number) << endl;
	return 0;
}

int solve(int towns_number, int regions_number)
{
	int members_number;
	cin >> members_number;
	vector<int> members(members_number);
	for (int i = 0; i != members_number; ++i) {
		cin >> members[i];
	}

	set<int> result;
	vector< vector<int> > regions(regions_number);
	for (int i = 0; i != regions_number; ++i) {
		int number;
		cin >> number;
		for (int j = 0; j != number; ++j) {
			int town;
			cin >> town;
			regions[i].push_back(town);
			for (int k = 0; k != members_number; ++k) {
				if (town == members[k]) {
					result.insert(i);
					break;
				}
			}
		}
	}

	vector< vector<int> > edges(towns_number + 1, vector<int>(towns_number + 1, -1));
	towns_to_edges(regions, edges);
	vector< vector<int> > graph(regions_number, vector<int>(regions_number, MAX));
	edges_to_graph(edges, graph);
	floyd_warshall(graph, regions_number);

	return calculate_minimum(graph, result);
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

void towns_to_edges(vector< vector<int> >& towns, vector< vector<int> >& edges)
{
	for (vector< vector<int> >::size_type i = 0; i != towns.size(); ++i) {
		for (vector<int>::size_type j = 0; j != towns[i].size() - 1; ++j) {
			edges[towns[i][j]][towns[i][j + 1]] = i;
		}
		edges[towns[i][towns[i].size() - 1]][towns[i][0]] = i;
	}
}

void edges_to_graph(vector< vector<int> >& edges, vector< vector<int> >& graph)
{
	for (vector< vector<int> >::size_type i = 0; i != edges.size(); ++i) {
		for (vector<int>::size_type j = 0; j != edges[i].size(); ++j) {
			if (edges[i][j] != -1) {
				graph[edges[i][j]][edges[j][i]] = 1;
			}
		}
	}
	for (vector< vector<int> >::size_type i = 0; i != graph.size(); ++i) {
		graph[i][i] = 0;
	}
}

int calculate_minimum(vector< vector<int> >& graph, set<int>& result)
{
	int min = MAX;
	for (vector< vector<int> >::size_type i = 0; i != graph.size(); ++i) {
	    int max = 0;
		for (set<int>::iterator iter = result.begin(); iter != result.end(); ++iter) {
			if (max < graph[*iter][i]) {
				max = graph[*iter][i];
			}
		}
		if (min > max) {
			min = max;
		}
	}
	return min;
}
