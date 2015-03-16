#include <iostream>
#include <vector>

using namespace std;

const int INFINITY = 0x7fffffff;

void solve();
int get_upper_bound(vector< vector<int> >& time, int scribers, int pages);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		solve();
	}
	return 0;
}

void solve()
{
	int pages, scribers;
	cin >> pages >> scribers;

	vector<int> book(pages + 1);
	vector< vector<int> > time(pages + 1, vector<int>(pages + 1));
	for (int i = 1; i <= pages; ++i) {
		cin >> book[i];
		time[i][i] = book[i];
	}
	for (int i = 1; i <= pages; ++i) {
		for (int j = i + 1; j <= pages; ++j) {
			time[i][j] = time[i][j - 1] + book[j];
		}
	}

	int limit = get_upper_bound(time, scribers, pages);
	vector<bool> mark(pages + 1, false);
	int sum = 0;
	int divide = 1;
	for (int i = pages; i > 0; --i) {
		sum += book[i];
		if (sum > limit) {
			mark[i] = true;
			sum = book[i];
			++divide;
		}
	}
	while (divide < scribers) {
		for (int i = 1; i <= pages; ++i) {
			if (!mark[i]) {
				mark[i] = true;
				++divide;
				break;
			}
		}
	}

	for (int i = 1; i <= pages; ++i) {
		cout << book[i] << ' ';
		if (mark[i]) {
			cout << '/' << ' ';
		}
	}
	cout << endl;
}

int get_upper_bound(vector< vector<int> >& time, int scribers, int pages)
{
	vector< vector<int> > dp(scribers + 1, vector<int>(pages + 1, INFINITY));
	for (int i = 1; i <= pages; ++i) {
        dp[1][i] = time[1][i];
    }
	for (int i = 2; i <= scribers; ++i) {
		for (int j = i; j <= pages; ++j) {
			for (int k = 1; k < j; ++k) {
				int temp = (dp[i - 1][k] > time[k + 1][j]) ? dp[i - 1][k] : time[k + 1][j];
				if (dp[i][j] > temp) {
					dp[i][j] = temp;
				}
			}
		}
	}
	return dp[scribers][pages];
}
