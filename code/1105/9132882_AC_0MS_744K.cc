#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(int depth);
int calculate(string& value, vector<int>& order);

int main()
{
	for (int i = 1; ; ++i) {
		int depth;
		cin >> depth;
		if (depth == 0) {
			break;
		}
		cout << "S-Tree #" << i << ":" << endl;
		solve(depth);
		cout << endl;
	}
	return 0;
}

void solve(int depth)
{
	vector<int> order(depth);
	for (int i = 0; i != depth; ++i) {
		char c;
		cin >> c >> order[i];
	}

	int size = 1;
	for (int i = 1; i <= depth; ++i) {
		size *= 2;
	}
	vector<char> result(size);
	for (int i = 0; i != size; ++i) {
		cin >> result[i];
	}

	int number;
	cin >> number;
	for (int i = 0; i != number; ++i) {
		string value;
		cin >> value;
		cout << result[calculate(value, order)];
	}
	cout << endl;
}

int calculate(string& value, vector<int>& order)
{
	string temp(value);
	for (vector<int>::size_type i = 0; i != order.size(); ++i) {
		temp[i] = value[order[i] - 1];
	}

    int base = 1;
    for (string::size_type i = 1; i != temp.size(); ++i) {
        base *= 2;
    }
	int sum = 0;
	for (string::size_type i = 0; i != temp.size(); ++i) {
		if (temp[i] == '1') {
			sum += base;
		}
		base /= 2;
	}
	return sum;
}
