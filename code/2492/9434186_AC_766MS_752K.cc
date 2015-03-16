#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Node {
	int parent;
	int relation;
};

void solve();
void make_set(vector<Node>& set);
void UNION(vector<Node>& set, int x, int y, int p, int q);
int find_set(vector<Node>& set, int x);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		cout << "Scenario #" << i << ":" << endl;
		solve();
		cout << endl;
	}
	return 0;
}

void solve()
{
	int bugs_number;
	cin >> bugs_number;
	vector<Node> set(bugs_number + 1);
	make_set(set);
	int messages;
	cin >> messages;
	bool judge = false;
	for (int i = 1; i <= messages; ++i) {
		int first, last;
		scanf("%d%d", &first, &last);

		int p = find_set(set, first);
		int q = find_set(set, last);
		if (p != q) {
			UNION(set, first, last, p, q);
		}
		else if (set[first].relation == set[last].relation) {
			judge = true;
		}
	}

	if (judge) {
		cout << "Suspicious bugs found!" << endl;
	}
	else {
		cout << "No suspicious bugs found!" << endl;
	}
}

void make_set(vector<Node>& set)
{
	for (vector<int>::size_type i = 1; i != set.size(); ++i) {
		set[i].parent = i;
		set[i].relation = 0;
	}
}

void UNION(vector<Node>& set, int x, int y, int p, int q)
{
	set[p].parent = q;
	set[p].relation = (set[x].relation + set[y].relation + 1) % 2;
}

int find_set(vector<Node>& set, int x)
{
	if (x != set[x].parent) {
		int temp = set[x].parent;
		set[x].parent = find_set(set, set[x].parent);
		set[x].relation = (set[x].relation + set[temp].relation) % 2;
	}
	return set[x].parent;
}
