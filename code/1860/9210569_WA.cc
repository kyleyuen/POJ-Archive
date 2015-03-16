#include <iostream>
#include <vector>

using namespace std;

struct Exchange {
	double rate;
	double commission;
};

bool solve(int currencies);
void bellman_ford_algorithm(vector< vector<Exchange> >& graph, int edges, int origin, int currencies, vector<double>& wealth);

int main()
{
	int currencies;
	cin >> currencies;
	if (solve(currencies)) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}

bool solve(int currencies)
{
	int edges, origin;
	double money;
	cin >> edges >> origin;
	cin >> money;

	vector< vector<Exchange> > graph(currencies + 1, vector<Exchange>(currencies + 1));
	int start, end;
	while (cin >> start >> end) {
		double rab, cab, rba, cba;
		cin >> rab >> cab >> rba >> cba;
		graph[start][end].rate = rab;
		graph[start][end].commission = cab;
		graph[end][start].rate = rba;
		graph[end][start].commission = cba;
	}

	vector<double> wealth(currencies + 1);
	wealth[origin] = money;
	bellman_ford_algorithm(graph, edges, origin, currencies, wealth);
	for (int i = 1; i <= currencies; ++i) {
		if (wealth[i] > money) {
			return true;
		}
	}
	return false;
}

void bellman_ford_algorithm(vector< vector<Exchange> >& graph, int edges, int origin, int currencies, vector<double>& wealth)
{
	for (int i = 1; i <= edges; ++i) {
		for (int i = 1; i <= currencies; ++i) {
			for (int j = 1; j <= currencies; ++j) {
				double result = (wealth[j] - graph[j][i].commission) * graph[j][i].rate;
				if (wealth[i] < result) {
					wealth[i] = result;
				}
			}
		}
	}
}
