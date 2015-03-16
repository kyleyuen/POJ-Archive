#include <iostream>
#include <cmath>

using namespace std;

int solve(int n);
int cut(int n);
int digit_sum(int number);
bool isprime(int n);

int main()
{
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << solve(n) << endl;
	}
	return 0;
}

int solve(int n)
{
	for (int i = n + 1; ; ++i) {
		if (!isprime(i) && digit_sum(i) == cut(i)) {
			return i;
		}
	}
}

int cut(int n)
{
	if (isprime(n)) {
		return digit_sum(n);
	}
	for (int i = sqrt(n); i >= 2; --i) {
		if (n % i == 0) {
			return cut(i) + cut(n / i);
		}
	}
}

int digit_sum(int number)
{
	int sum = 0;
	while (number != 0) {
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

bool isprime(int n)
{
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
