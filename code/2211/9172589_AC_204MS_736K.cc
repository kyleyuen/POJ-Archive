#include <iostream>

using namespace std;

int answer[13];
int pay[13];

void initial();
int solve(int n, int k);

int main()
{
	initial();
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		int n, k;
		cin >> n >> k;
		cout << "Variace cislo " << i << " ma poradove cislo " << solve(n, k) << "." << endl;
	}
	return 0;
}

void initial()
{
	answer[0] = 1;
	for (int i = 1; i <= 12; ++i) {
		answer[i] = answer[i - 1] * i;
	}
}

int solve(int n, int k)
{
    for (int i = 1; i <= 12; ++i) {
        pay[i] = i - 1;
	}

	int result = 1;
	for (int i = 1; i <= k; ++i) {
		int digit;
		cin >> digit;
		result += pay[digit] * answer[n - i] / answer[n - k];
		for (int i = digit; i <= n; ++i) {
            --pay[i];
		}
	}
	return result;
}
