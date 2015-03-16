#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Compare {
public:
	bool operator() (const string& lhs, const string& rhs) {
		int m = lhs.size();
		int n = rhs.size();
		for (int i = 0, j = 0; i != m && j != n; ++i, ++j) {
			int a = tolower(lhs[i]);
			int b = tolower(rhs[j]);
			if (a < b) {
				return true;
			}
			else if (a > b) {
				return false;
			}
		}
		return m < n;
	}
};

void solve(string& line);
bool isnumber(const string& str);

int main()
{
	string line;
	while (getline(cin, line)) {
		if (line == ".") {
			break;
		}
		solve(line);
	}
	return 0;
}

void solve(string& line)
{
	for (string::size_type i = 0; i != line.size(); ++i) {
		if (line[i] == ',' || line[i] == '.') {
			line[i] = ' ';
		}
	}

	vector<string> words;
	vector<int> numbers;
	vector<int> position;

	istringstream iss(line);
	string temp;
	int size = 0;
	while (iss >> temp) {
		if (isnumber(temp)) {
			istringstream is(temp);
			int t;
			is >> t;
			numbers.push_back(t);
			position.push_back(size);
		}
		else {
			words.push_back(temp);
		}
		++size;
	}

	sort(numbers.begin(), numbers.end());
	sort(words.begin(), words.end(), Compare());
	int a = 0, b = 0;
	for (int i = 0; i != size; ++i) {
		if (find(position.begin(), position.end(), i) == position.end()) {
			cout << words[a];
			++a;
		}
		else {
			cout << numbers[b];
			++b;
		}
		if (i == size - 1) {
			cout << "." << endl;
		}
		else {
			cout << ", ";
		}
	}
}

bool isnumber(const string& str)
{
    for (string::size_type i = 0; i != str.size(); ++i) {
        if (!(isdigit(str[i]) || str[i] == '-')) {
            return false;
        }
    }
    return true;
}
