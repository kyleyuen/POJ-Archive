#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Compare {
public:
    bool operator() (int lhs, int rhs) {
        return lhs > rhs;
    }
};

void solve(int target, int size);
void visit(vector<int>& array, int i, int n, int current, int target, vector< deque<int> >& reserve);

deque<int> queue;
int counter = 0;

int main()
{
	int target, size;
	while (cin >> target >> size) {
		if (target == 0 && size == 0) {
			break;
		}
		solve(target, size);
	}
	return 0;
}

void solve(int target, int size)
{
	vector<int> array(size);
	for (int i = 0; i != size; ++i) {
		cin >> array[i];
	}
	sort(array.begin(), array.end(), Compare());

	cout << "Sums of " << target << ":" << endl;
	counter = 0;
	vector< deque<int> > reserve;
	visit(array, 0, size, 0, target, reserve);
	if (counter == 0) {
		cout << "NONE" << endl;
	}
}

void visit(vector<int>& array, int i, int n, int current, int target, vector< deque<int> >& reserve)
{
	if (current == target) {
		++counter;
		if (find(reserve.begin(), reserve.end(), queue) == reserve.end()) {
			deque<int>::iterator iter = queue.begin();
			cout << *iter;
			++iter;
			while (iter != queue.end()) {
				cout << "+" << *iter;
				++iter;
			}
			cout << endl;
			reserve.push_back(queue);
		}
		return;
	}
	if (i == n) {
		return;
	}

	queue.push_back(array[i]);
	visit(array, i + 1, n, current + array[i], target, reserve);
	queue.pop_back();
	visit(array, i + 1, n, current, target, reserve);
}
