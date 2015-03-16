#include <iostream>
#include <stack>

using namespace std;

void solve(int coaches);

int main()
{
	int coaches;
	while (cin >> coaches) {
		if (coaches == 0) {
			break;
		}
		solve(coaches);
		cout << endl;
	}
	return 0;
}

void solve(int coaches)
{
	while (true) {
		int index = 1;
		stack<int> stk;
		stk.push(index);
		for (int i = 0; i != coaches; ++i) {
		    int current;
			cin >> current;

			if (current == 0) {
                return;
			}

			if (stk.empty()) {
                ++index;
                stk.push(index);
			}
			while (stk.top() != current) {
				if (index == coaches) {
					break;
				}
				++index;
				stk.push(index);
			}
			if (stk.top() == current) {
                stk.pop();
			}
		}

		if (stk.empty()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
