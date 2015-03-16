#include <iostream>
#include <vector>

using namespace std;

bool solve();

int main()
{
	while (solve());
	return 0;
}

bool solve()
{
	vector<int> array;

	int temp;
	cin >> temp;
	if (temp == -1) {
		return false;
	}
	else {
		array.push_back(temp);
	}
	while (cin >> temp) {
		if (temp == 0) {
			break;
		}
		array.push_back(temp);
	}

	int result = 0;
	for (vector<int>::size_type i = 0; i != array.size(); ++i) {
		for (vector<int>::size_type j = 0; j != array.size(); ++j) {
			if (array[i] * 2 == array[j]) {
				++result;
			}
		}
	}
	cout << result << endl;
	return true;
}
