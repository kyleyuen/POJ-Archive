#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "n e" << endl;
    cout << "- -----------" << endl;
	double result  = 0;
	int base = 1;
	cout << setprecision(10);
	for (int i = 0; i != 10; ++i) {
		result += 1.0 / base;
		cout << i << ' ' << result << endl;
		base *= (i + 1);
	}
	return 0;
}
