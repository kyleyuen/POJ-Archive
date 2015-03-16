#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(const string& line);
void calculate(const string& line, vector< vector<int> >& record);
void print(const string& line, vector< vector<int> >& record, int start, int end);

int main()
{
	string line;
	getline(cin, line);
	solve(line);
	return 0;
}

void solve(const string& line)
{
	unsigned length = line.size();
	vector< vector<int> > record(length, vector<int>(length));
	calculate(line, record);
	print(line, record, 0, length - 1);
}

void calculate(const string& line, vector< vector<int> >& record)
{
	int length = line.size();
	vector< vector<int> > dp(length, vector<int>(length));
	for (int i = 0; i < length; ++i) {
		dp[i][i] = 1;
	}
	for (int len = 1; len < length; ++len) {
		for (int i = 0; i < length - len; ++i) {
			int j = len + i;
			dp[i][j] = 100000;
			if ((line[i] == '(' && line[j] == ')') || (line[i] == '[' && line[j] == ']')) {
				dp[i][j] = dp[i + 1][j - 1];
				record[i][j] = -1;
			}
			for (int k = i; k < j; ++k) {
				if (dp[i][j] > dp[i][k] + dp[k + 1][j]) {
					dp[i][j] = dp[i][k] + dp[k + 1][j];
					record[i][j] = k;
				}
			}
		}
	}
}

void print(const string& line, vector< vector<int> >& record, int start, int end)
{
	if (start > end) {
		return;
	}
	else if (start == end) {
		if (line[start] == '(' || line[end] == ')') {
			cout << "()";
		}
		else if (line[start] == '[' || line[end] == ']') {
			cout << "[]";
		}
	}
	else if (record[start][end] == -1) {
		cout << line[start];
		print(line, record, start + 1, end - 1);
		cout << line[end];
	}
	else {
		print(line, record, start, record[start][end]);
		print(line, record, record[start][end] + 1, end);
	}
}
