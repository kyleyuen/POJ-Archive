#include <iostream>

using namespace std;

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		int r, e, c;
		cin >> r >> e >> c;
		if (r < e - c) {
			cout << "advertise" << endl;
		}
		else if (r > e - c) {
			cout << "do not advertise" << endl;
		}
		else {
			cout << "does not matter" << endl;
		}
	}
	return 0;
}
