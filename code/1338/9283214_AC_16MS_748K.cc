#include <iostream>

using namespace std;

long long number[1501];

void calculate();

int main()
{
	calculate();
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		cout << number[n] << endl;
	}
}

void calculate()
{
	number[1] = 1;
	int two = 1, three = 1, five = 1;
	for (int i = 2; i <= 1500; ++i) {
		int result = number[two] * 2;
		if (result > number[three] * 3) {
			result = number[three] * 3;
		}
		if (result > number[five] * 5) {
			result = number[five] * 5;
		}

        number[i] = result;
		if (number[i] == number[two] * 2) {
            ++two;
		}
		if (number[i] == number[three] * 3) {
            ++three;
		}
		if (number[i] == number[five] * 5) {
            ++five;
		}
	}
}
