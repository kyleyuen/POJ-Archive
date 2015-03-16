#include <iostream>
#include <algorithm>

using namespace std;

struct Ratio {
	int numerator;
	int denominator;
};

void solve(int gainer, int loser);

int main()
{
	int gainer, loser;
	while (cin >> gainer >> loser) {
		solve(gainer, loser);
		cout << endl;
	}
	return 0;
}

void solve(int gainer, int loser)
{
	Ratio result;
	result.numerator = (double)(gainer) / (double)loser + 0.5;
	result.denominator = 1;
	cout << result.numerator << '/' << result.denominator << endl;
	for (int i = 2; i <= loser; ++i) {
		Ratio current;
		current.numerator = (double)(i * gainer) / (double)loser + 0.5;
		current.denominator = i;
		if(result.denominator * abs(gainer * current.denominator - loser * current.numerator) < current.denominator * abs(gainer * result.denominator - loser * result.numerator)) {
			result = current;
			cout << result.numerator << '/' << result.denominator << endl;
		}
		if (result.numerator * loser == result.denominator * gainer) {
			break;
		}
	}
}
