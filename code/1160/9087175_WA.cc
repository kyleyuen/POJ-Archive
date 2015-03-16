#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int villages_number, int offices_number);

int main()
{
	int villages_number;
	int offices_number;
	cin >> villages_number >> offices_number;
	cout << solve(villages_number, offices_number) << endl;
	return 0;
}

int solve(int villages_number, int offices_number)
{
	vector<int> villages(villages_number);
	for (int i = 0; i != villages_number; ++i) {
		cin >> villages[i];
	}

	vector<int> gap(villages_number);
	for (int i = 1; i != villages_number; ++i) {
		gap[i] = villages[i] - villages[i - 1];
	}

	vector<int> mark;
	mark.push_back(0);
	for (int i = 0; i != offices_number - 1; ++i) {
		int index = 1;
		for (int j = 2; j != villages_number; ++j) {
			if (gap[j] > gap[index]) {
				index = j;
			}
		}
		gap[index] = 0;
		mark.push_back(index);
	}
	mark.push_back(villages_number);
	sort(mark.begin(), mark.end());

	int distance = 0;
	for (vector<int>::size_type i = 1; i != mark.size(); ++i) {
		int start = mark[i - 1];
		int end = mark[i];
		if (end - start == 1) {
			continue;
		}

		distance += villages[start + 1] - villages[start];
		if (end - start > 2) {
			for (int j = start + 2; j != end; ++j) {
				distance += villages[j] - villages[start + 1];
			}
		}
	}
	return distance;
}
