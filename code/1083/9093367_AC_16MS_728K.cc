#include <iostream>
#include <vector>

using namespace std;

int solve();

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 0; i != total_cases; ++i) {
		cout << solve() << endl;
	}
	return 0;
}

int solve()
{
	int number;
	cin >> number;
	vector<int> rooms(200, 0);
	for (int i = 0; i != number; ++i) {
	    int start, end;
		cin >> start >> end;
		if (start > end) {
            int temp = start;
            start = end;
            end = temp;
		}
		for (int j = (start - 1) / 2; j <= (end - 1) / 2; ++j) {
            ++rooms[j];
		}
	}

    int max = 0;
    for (vector<int>::size_type i = 0; i != rooms.size(); ++i) {
        if (rooms[i] > max) {
            max = rooms[i];
        }
    }
    return max * 10;
}
