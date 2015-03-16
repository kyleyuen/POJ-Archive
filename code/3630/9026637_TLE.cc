#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool solve();
bool isPrefix(const string& lhs, const string& rhs);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 0; i != total_cases; ++i) {
		if (solve()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

bool solve()
{
	int list_size;
	cin >> list_size;

	vector<string> phone_list;
	for (int i = 0; i != list_size; ++i) {
		string phone_number;
		cin >> phone_number;
		phone_list.push_back(phone_number);
	}

	for (vector<string>::size_type i = 0; i != phone_list.size(); ++i) {
		for (vector<string>::size_type j = i + 1; j != phone_list.size(); ++j) {
			if (isPrefix(phone_list[i], phone_list[j])) {
				return false;
			}
		}
	}
	return true;
}

bool isPrefix(const string& lhs, const string& rhs)
{
	if (lhs.size() < rhs.size()) {
        return rhs.compare(0, lhs.size(), lhs) == 0;
	}
	else {
        return lhs.compare(0, rhs.size(), rhs) == 0;
	}
}
