#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Node {
	int parent;
	int relation;
};

int solve(int animals, int statements);
void make_set(vector<Node>& set);
void UNION(vector<Node>& set, int x, int y, int a, int b, int judge);
int find_set(vector<Node>& set, int x);

int main()
{
	int animals, statements;
	cin >> animals >> statements;
	cout << solve(animals, statements) << endl;
	return 0;
}

int solve(int animals, int statements)
{
	vector<Node> set(animals + 1);
	make_set(set);
	int result = 0;
	for (int i = 0; i != statements; ++i) {
		int judge, first, last;
		scanf("%d%d%d", &judge, &first, &last);

		if (first > animals || last > animals) {
			++result;
			continue;
		}
		int p = find_set(set, first);
		int q = find_set(set, last);
		if (p != q) {
			UNION(set, first, last, p, q, judge);
		}
		else if (set[first].relation != (set[last].relation + judge + 2) % 3) {
			++result;
		}
	}
	return result;
}

void make_set(vector<Node>& set)
{
	for (vector<int>::size_type i = 1; i != set.size(); ++i) {
		set[i].parent = i;
		set[i].relation = 0;
	}
}

void UNION(vector<Node>& set, int a, int b, int p, int q, int judge)
{
	set[p].parent = q;
	set[p].relation = (set[b].relation - set[a].relation + 2 + judge) % 3;
}

int find_set(vector<Node>& set, int x)
{
	if (x != set[x].parent) {
		int temp = set[x].parent;
		set[x].parent = find_set(set, set[x].parent);
		set[x].relation = (set[x].relation + set[temp].relation) % 3;
	}
	return set[x].parent;
}
