#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int target;
vector< list<int> > collection;
list<int> path;

void solve(int rooms_number);
void visit(vector< vector<int> >& graph, vector<bool>& state, int room, int length);
int calculate();

int main()
{
	int rooms_number;
	cin >> rooms_number >> target;
	solve(rooms_number);
	return 0;
}

void solve(int rooms_number)
{
	vector< vector<int> > graph(rooms_number);
	int start, end;
	while (cin >> start >> end) {
		graph[start].push_back(end);
	}

	vector<bool> state(rooms_number, true);
	visit(graph, state, 0, 0);

	int result = calculate();
	cout << "Put guards in room " << result << "." << endl;
}

void visit(vector< vector<int> >& graph, vector<bool>& state, int room, int length)
{
	if (room == target) {
		collection.push_back(path);
		return;
	}
	else {
		state[room] = false;
		path.push_back(room);
	}

	for (vector<int>::iterator iter = graph[room].begin(); iter != graph[room].end(); ++iter) {
		if (state[*iter]) {
			visit(graph, state, *iter, length + 1);
		}
	}
	path.pop_back();
}

int calculate()
{
    if (collection.size() == 1) {
        return collection[0].back();
    }
	for (list<int>::reverse_iterator iter = collection[0].rbegin(); iter != collection[0].rend(); ++iter) {
		bool ensure = true;
		for (vector< list<int> >::size_type j = 1; j != collection.size(); ++j) {
			if (find(collection[j].begin(), collection[j].end(), *iter) == collection[j].end()) {
				ensure = false;
				break;
			}
		}
		if (ensure) {
			return *iter;
		}
	}
	return -1;
}
