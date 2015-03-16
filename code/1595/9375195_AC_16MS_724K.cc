#include <iostream>
#include <vector>

using namespace std;

void initial();
bool isPrime(int n);
void solve(int n, int c);

vector<int> prime;
vector<int> record(1001);

int main()
{
	initial();
	int n, c;
	while (cin >> n >> c) {
		solve(n, c);
	}
	return 0;
}

void initial()
{
    prime.push_back(1);
	for (int i = 2; i != 1000; ++i) {
		if (isPrime(i)) {
			prime.push_back(i);
		}
	}
	prime.push_back(10000000);

	int index = 0;
	for (int i = 1; i <= 1000; ++i) {
		if (i >= prime[index]) {
			++index;
		}
		record[i] = index;
	}
}

bool isPrime(int n)
{
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void solve(int n, int c)
{
	cout << n << ' ' << c << ':';
	int start;
	int end;
	if (c > record[n] / 2) {
        start = 0;
        end = record[n] - 1;
	}
	else if (record[n] % 2 == 0) {
		start = record[n] / 2 - c;
		end = record[n] / 2 + c - 1;
	}
	else {
		start = record[n] / 2 - c + 1;
		end = record[n] / 2 + c - 1;
	}
	for (int i = start; i <= end; ++i) {
		cout << ' ' << prime[i];
	}
	cout << endl << endl;
}
