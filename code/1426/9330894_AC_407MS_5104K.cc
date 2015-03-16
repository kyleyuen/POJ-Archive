#include <iostream>
#include <queue>

using namespace std;

long long solve(int n);

int main()
{
    int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << solve(n) << endl;
	}
}

long long solve(int n)
{
	deque<long long> queue;
	queue.push_back(1);
	while (!queue.empty()) {
		long long value = queue.front();
		queue.pop_front();
		if (value % n == 0) {
			return value;
		}
		queue.push_back(value * 10);
		queue.push_back(value * 10 + 1);
	}
	return 0;
}
