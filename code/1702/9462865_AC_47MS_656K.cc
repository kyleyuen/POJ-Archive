#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int weight);
string toTernary(int weight);
void toBalance(string& number);
void print(const string& number);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		int weight;
		cin >> weight;
		solve(weight);
	}
	return 0;
}

void solve(int weight)
{
	string number = toTernary(weight);
	toBalance(number);
	print(number);
}

string toTernary(int weight)
{
	string result;
	while (weight != 0) {
		result.push_back(weight % 3);
		weight /= 3;
	}
	return result;
}

void toBalance(string& number)
{
	int length = number.size();
	for (int i = 0; i < length - 1; ++i) {
		if (number[i] == 2) {
			number[i] = -1;
			++number[i + 1];
		}
		else if (number[i] == 3) {
			number[i] = 0;
			++number[i + 1];
		}
	}
	if (number[length - 1] == 2) {
		number[length - 1] = -1;
		number.push_back(1);
	}
	else if (number[length - 1] == 3) {
		number[length - 1] = 0;
		number.push_back(1);
	}
}

void print(const string& number)
{
	vector<int> left;
	vector<int> right;
	int base = 1;
	for (string::size_type i = 0; i != number.size(); ++i) {
		if (number[i] == -1) {
			left.push_back(base);
		}
		if (number[i] == 1) {
			right.push_back(base);
		}
		base *= 3;
	}

	if (left.size() == 0) {
		cout << "empty ";
	}
	else {
		for (vector<int>::size_type i = 0; i != left.size(); ++i) {
			cout << left[i];
			if (i == left.size() - 1) {
				cout << ' ';
			}
			else {
				cout << ',';
			}
		}
	}
	if (right.size() == 0) {
		cout << "empty ";
	}
	else {
		for (vector<int>::size_type i = 0; i != right.size(); ++i) {
			cout << right[i];
			if (i == right.size() - 1) {
				cout << ' ';
			}
			else {
				cout << ',';
			}
		}
	}
	cout << endl;
}
