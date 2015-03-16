#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int k);
void search(vector< vector<char> >& board, vector<bool>& state, int n, int k, int& result, int index);

int main()
{
	int n, k;
	while (cin >> n >> k) {
		if (n == -1 && k == -1) {
			break;
		}
		cout << solve(n, k) << endl;
	}
	return 0;
}

int solve(int n, int k)
{
	vector< vector<char> > board(n + 2, vector<char>(n + 2));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
            cin >> board[i][j];
		}
	}

	int result = 0;
	vector<bool> state(n + 1, true);
	search(board, state, n, k, result, 1);
	return result;
}

void search(vector< vector<char> >& board, vector<bool>& state, int n, int k, int& result, int index)
{
	if (k == 0) {
		++result;
		return;
	}
	if (index > n) {
        return;
	}

	for (int j = 1; j <= n; ++j) {
        if (board[index][j] == '#' && state[j]) {
            state[j] = false;
            search(board, state, n, k - 1, result, index + 1);
            state[j] = true;
        }
    }
    search(board, state, n, k, result, index + 1);
}
