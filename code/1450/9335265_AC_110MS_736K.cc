#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int total_cases;
	cin >> total_cases;
	cout << fixed << setprecision(3);
	for (int i = 1; i <= total_cases; ++i) {
		int m, n;
		cin >> m >> n;
		int result = m * n;
		cout << "Scenario #" << i << ":" << endl;
		cout << result;
		if (result % 2 == 0) {
			cout << ".00" << endl;
		}
		else {
			cout << ".41" << endl;
		}
		cout << endl;
	}
	return 0;
}
