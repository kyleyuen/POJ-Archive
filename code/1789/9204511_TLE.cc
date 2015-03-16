#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 10;

int solve(int trucks);
int differ(const string& lhs, const string& rhs);
int prim_algorithm(vector< vector<int> >& graph, int trucks);

int main()
{
	int trucks;
	while (cin >> trucks) {
		if (trucks == 0) {
			break;
		}
		cout << "The highest possible quality is 1/" << solve(trucks) << "." << endl;
	}
	return 0;
}

int solve(int trucks)
{
	vector< vector<int> > graph(trucks, vector<int>(trucks, MAX));
	vector<string> types;
	for (int i = 0; i != trucks; ++i) {
		string line;
		cin >> line;
		types.push_back(line);
		for (int j = 0; j != i; ++j) {
			int result = differ(line, types[j]);
			graph[i][j] = graph[j][i] = result;
		}
	}

	return prim_algorithm(graph, trucks);
}

int differ(const string& lhs, const string& rhs)
{
	int result = 0;
	for (string::size_type i = 0; i != lhs.size(); ++i) {
		if (lhs[i] != rhs[i]) {
			++result;
		}
	}
	return result;
}

int prim_algorithm(vector< vector<int> >& graph, int trucks)
{
	int result = 0;
	vector<bool> state(trucks, false);
	state[0] = true;
	for (int i = 1; i != trucks; ++i) {
		int min = 1000000;
		int index = -1;
		for (int j = 0; j != trucks; ++j) {
			if (!state[j]) {
				continue;
			}
			for (int k = 0; k != trucks; ++k) {
				if (state[k]) {
					continue;
				}
				if (min > graph[j][k]) {
					min = graph[j][k];
					index = k;
				}
			}
		}
		result += min;
		state[index] = true;
	}
	return result;
}
