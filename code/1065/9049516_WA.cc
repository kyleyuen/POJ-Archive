#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stick {
	int length;
	int weight;
};

class Compare {
public:
	bool operator() (const Stick& lhs, const Stick& rhs) {
		return (lhs.length < rhs.length) || (lhs.length == rhs.length && lhs.weight < rhs.weight);
	}
};

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
	int sticks_number;
	cin >> sticks_number;
	vector<Stick> sticks(sticks_number);
	for (int i = 0; i != sticks_number; ++i) {
		cin >> sticks[i].length >> sticks[i].weight;
	}
	sort(sticks.begin(), sticks.end(), Compare());

	int time = 1;
	vector<bool> state(sticks_number, false);
	for (int i = 0; i != sticks_number; ++i) {
	    if (state[i]) {
            continue;
	    }
	    state[i] = true;
		for (int j = i + 1; j != sticks_number; ++j) {
            if (state[j]) {
                continue;
            }
            if (sticks[i].length <= sticks[j].length && sticks[i].weight <= sticks[j].weight) {
                state[j] = true;
            }
            else {
                ++time;
                break;
            }
		}
	}
	return time;
}
