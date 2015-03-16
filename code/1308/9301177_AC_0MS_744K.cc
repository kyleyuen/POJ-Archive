#include <iostream>
#include <map>
#include <list>

using namespace std;

bool solve(int index);
bool dfs(map<int, list<int> >& tree, map<int, bool>& record, int start);
bool istravelled(map<int, bool>& record);

int main()
{
	for (int i = 1; solve(i); ++i);
	return 0;
}

bool solve(int index)
{
	map<int, list<int> > tree;
	map<int, bool> record;
	int start, end;
	cin >> start >> end;
	if (start == -1 && end == -1) {
        return false;
    }
	if (start == 0 && end == 0) {
        cout << "Case " << index << " is a tree." << endl;
        return true;
	}
	tree[start].push_back(end);
    record.insert(make_pair(start, true));
    record.insert(make_pair(end, true));
	while (cin >> start >> end) {
		if (start == 0 && end == 0) {
			break;
		}
		tree[start].push_back(end);
		record.insert(make_pair(start, true));
		record.insert(make_pair(end, true));
	}

	for (map<int, list<int> >::iterator iter = tree.begin(); iter != tree.end(); ++iter) {
	    for (map<int, bool>::iterator it = record.begin(); it != record.end(); ++it) {
            it->second = true;
	    }
		if (dfs(tree, record, iter->first) && istravelled(record)) {
			cout << "Case " << index << " is a tree." << endl;
			return true;
		}
	}
	cout << "Case " << index << " is not a tree." << endl;
	return true;
}

bool dfs(map<int, list<int> >& tree, map<int, bool>& record, int start)
{
	record[start] = false;
	for (list<int>::iterator iter = tree[start].begin(); iter != tree[start].end(); ++iter) {
		if (!record[*iter]) {
			return false;
		}
		if (!dfs(tree, record, *iter)) {
            return false;
		}
	}
	return true;
}

bool istravelled(map<int, bool>& record)
{
	for (map<int, bool>::iterator iter = record.begin(); iter != record.end(); ++iter) {
		if (iter->second) {
			return false;
		}
	}
	return true;
}
