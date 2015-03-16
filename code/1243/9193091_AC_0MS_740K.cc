#include <iostream>
#include <vector>

using namespace std;

int solve(int guess, int lifeline);

int main()
{
	for (int i = 1; ; ++i) {
		int guess, lifeline;
		cin >> guess >> lifeline;
		if (guess == 0 && lifeline == 0) {
			break;
		}
		cout << "Case " << i << ": " << solve(guess, lifeline) << endl;
	}
	return 0;
}

int solve(int guess, int lifeline)
{
	vector< vector<int> > array(guess + 1, vector<int>(lifeline + 1));
	for (int i = 0; i <= guess; ++i) {
		array[i][0] = i;
	}
	for (int i = 1; i <= guess; ++i) {
		for (int j = 1; j <= lifeline; ++j) {
			array[i][j] = array[i - 1][j - 1] + array[i - 1][j] + 1;
		}
	}
	return array[guess][lifeline];
}
