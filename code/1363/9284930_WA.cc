#include <iostream>
#include <vector>

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
	vector<int> order(coaches);
	while (true) {
		cin >> order[0];
		if (order[0] == 0) {
			break;
		}
		for (int i = 1; i != coaches; ++i) {
			cin >> order[i];
		}

		bool judge = true;
		for (int i = 0; i != coaches - 1; ++i) {
			for (int j = i + 1; j != coaches; ++j) {
				if (order[i] < order[j]) {
					break;
				}
				if (order[j - 1] < order[j]) {
					judge = false;
				}
			}
			if (!judge) {
				break;
			}
		}

		if (judge) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}
