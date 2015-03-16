#include <iostream>

using namespace std;

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		int zombies, brains;
		cin >> zombies >> brains;
		if (zombies >= brains) {
			cout << "MMM BRAINS" << endl;
		}
		else {
			cout << "NO BRAINS" << endl;
		}
	}
	return 0;
}
