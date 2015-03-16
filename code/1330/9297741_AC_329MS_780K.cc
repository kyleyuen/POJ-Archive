#include <iostream>
#include <vector>

using namespace std;

int solve();

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
	int nodes;
	cin >> nodes;

	vector<int> path(nodes + 1, 0);
	for (int i = 1; i != nodes; ++i) {
		int parent, child;
		cin >> parent >> child;
		path[child] = parent;
	}

	int first, second;
	cin >> first >> second;
	while (first != 0) {
		for (int i = second; i != 0; i = path[i]) {
			if (i == first) {
				return i;
			}
		}
		first = path[first];
	}
	return 0;
}
