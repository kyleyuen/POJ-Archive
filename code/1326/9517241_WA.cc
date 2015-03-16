#include <iostream>
#include <string>

using namespace std;

int solve(string start);

int main()
{
	string start;
	while (cin >> start) {
		if (start == "#") {
			break;
		}
		cout << solve(start) << endl;
	}
	return 0;
}

int solve(string start)
{
	string end;
	int mileage;
	char type;

	int result = 0;
	do {
		if (start == "0") {
			break;
		}

		cin >> end >> mileage >> type;
		switch (type) {
		case 'F':
			mileage += mileage;
			break;
		case 'B':
			mileage += (mileage + 1) / 2;
			break;
        default:
            break;
		}
		if (mileage < 500) {
			mileage = 500;
		}
		result += mileage;
	} while (cin >> start);
	return result;
}
