#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve(string& line);
void add_edge(vector< vector<int> >& graph, vector<int>& degree, string& line, int& result);
int floyd(vector< vector<int> >& graph, int start, int end);

int main()
{
	string line;
	while (cin >> line) {
		cout << solve(line) << endl;
	}
	return 0;
}

int solve(string& line)
{
	if (line == "deadend") {
		return 0;
	}

	int result = 0;
	vector< vector<int> > graph(26, vector<int>(26, 1000000000));
	for (int i = 0; i != 26; ++i) {
        graph[i][i] = 0;
    }
	vector<int> degree(26, 0);
	add_edge(graph, degree, line, result);
	while (cin >> line) {
		if (line == "deadend") {
			break;
		}
		add_edge(graph, degree, line, result);
	}

	int start = -1;
	int end = -1;
	bool judge = false;
	for (int i = 0; i != 26; ++i) {
		if (degree[i] % 2 == 1) {
			if (judge) {
				end = i;
			}
			else {
				start = i;
			}
			judge = true;
		}
	}

	if (judge) {
		result += floyd(graph, start, end);
	}
	return result;
}

void add_edge(vector< vector<int> >& graph, vector<int>& degree, string& line, int& result)
{
	int start = line[0] - 'a';
	int end = line[line.size() - 1] - 'a';
	int length = line.size();
	graph[start][end] = graph[end][start] = length;
	++degree[start];
	++degree[end];
	result += length;
}

int floyd(vector< vector<int> >& graph, int start, int end)
{
	for (int k = 0; k != 26; ++k) {
	    for (int i = 0; i != 26; ++i) {
            for (int j = 0; j != 26; ++j) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	return graph[start][end];
}
