#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int parent;
	int rank;
	int size;
};

int solve(int students, int groups);
void make_set(vector<Node>& set);
void UNION(vector<Node>& set, int x, int y);
void link(vector<Node>& set, int x, int y);
int find_set(vector<Node>& set, int x);

int main()
{
	int students, groups;
	while (cin >> students >> groups) {
		if (students == 0 && groups == 0) {
			break;
		}
		cout << solve(students, groups) << endl;
	}
	return 0;
}

int solve(int students, int groups)
{
	vector<Node> set(students);
	make_set(set);
	for (int i = 0; i != groups; ++i) {
		int members;
		cin >> members;
		int previous;
		cin >> previous;
		for (int j = 1; j != members; ++j) {
			int current;
			cin >> current;
            UNION(set, previous, current);
		}
	}

	return set[find_set(set, 0)].size;
}

void make_set(vector<Node>& set)
{
	for (vector<int>::size_type i = 0; i != set.size(); ++i) {
		set[i].parent = i;
		set[i].rank = 0;
		set[i].size = 1;
	}
}

void UNION(vector<Node>& set, int x, int y)
{
	link(set, find_set(set, x), find_set(set, y));
}

void link(vector<Node>& set, int x, int y)
{
	if (set[x].rank > set[y].rank) {
		set[y].parent = x;
		set[x].size = set[x].size + set[y].size;
	}
	else {
		set[x].parent = y;
		set[y].size = set[x].size + set[y].size;
		if (set[x].rank == set[y].rank) {
			++set[y].rank;
		}
	}
}

int find_set(vector<Node>& set, int x)
{
	if (x != set[x].parent) {
		set[x].parent = find_set(set, set[x].parent);
	}
	return set[x].parent;
}
