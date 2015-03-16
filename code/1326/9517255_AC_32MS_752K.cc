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
	int result = 0;
	do {
		if (start == "0") {
			break;
		}

        string end;
        int mileage;
        char type;
		cin >> end >> mileage >> type;
		switch (type) {
		case 'F':
			mileage += mileage;
			break;
		case 'B':
			mileage += (mileage + 1) / 2;
			break;
        case 'Y':
            if (mileage < 500) {
                mileage = 500;
            }
            break;
		}
		result += mileage;
	} while (cin >> start);
	return result;
}
