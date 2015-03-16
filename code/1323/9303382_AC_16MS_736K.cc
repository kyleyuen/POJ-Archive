#include <iostream>
#include <vector>

using namespace std;

int solve(int players, int cards);

int main()
{
	for (int i = 1; ; ++i) {
		int players, cards;
		cin >> players >> cards;
		if (players == 0 && cards == 0) {
			break;
		}

		cout << "Case " << i << ": " << solve(players, cards) << endl;
	}
	return 0;
}

int solve(int players, int cards)
{
	vector<int> state(cards * players + 1, false);
	for (int i = 0; i != cards; ++i) {
		int temp;
		cin >> temp;
		state[temp] = true;
	}

	int result = 0;
	int current = 0;
	for (int i = players * cards; i != 0; --i) {
		if (state[i]) {
			++current;
		}
		else {
			--current;
		}
		if (result < current) {
			result = current;
		}
	}
	return result;
}
