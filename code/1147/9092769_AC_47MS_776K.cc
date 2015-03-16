#include <iostream>
#include <vector>

using namespace std;

void solve(int length);

int main()
{
	int length;
	cin >> length;
	solve(length);
	return 0;
}

void solve(int length)
{
    vector<int> column(length);
    for (int i = 0; i != length; ++i) {
        cin >> column[i];
    }

	int zero_index = 0;
	int one_index = 0;
	for (int i = 0; i != length; ++i) {
		if (column[i] == 0) {
			++one_index;
		}
	}

	vector<int> array(length);
	for (int i = 0; i != length; ++i) {
		if (column[i] == 0) {
			array[i] = zero_index;
			++zero_index;
		}
		else {
			array[i] = one_index;
			++one_index;
		}
	}
	vector<int> next(length);
	for (int i = 0; i != length; ++i) {
		next[array[i]] = i;
	}

	int index = 0;
	for (int i = 0; i != length - 1; ++i) {
		cout << column[next[index]] << ' ';
		index = next[index];
	}
	cout << column[next[index]] << endl;
}
