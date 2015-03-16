#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Compare {
public:
	bool operator() (char lhs, char rhs) {
		return lhs > rhs;
	}
};

int array[26][5];

void initial();
void solve(int result, string& code);

int main()
{
	initial();
	int result;
	string code;
	while (cin >> result >> code) {
		if (result == 0 && code == "END") {
			break;
		}
		solve(result, code);
	}
	return 0;
}

void initial()
{
	for (int i = 0; i != 26; ++i) {
		array[i][0] = i + 1;
		for (int j = 1; j != 5; ++ j) {
			array[i][j] = array[i][j - 1] * (i + 1);
		}
	}
}

void solve(int result, string& code)
{
	sort(code.begin(), code.end(), Compare());
	for (string::size_type i = 0; i != code.size(); ++i) {
		for (string::size_type j = 0; j != code.size(); ++j) {
			if (j == i) { continue; }
			for (string::size_type k = 0; k != code.size(); ++k) {
				if (k == i || k == j) { continue; }
				for (string::size_type l = 0; l != code.size(); ++l) {
					if (l == i || l == j || l == k) { continue; }
					for (string::size_type m = 0; m != code.size(); ++m) {
						if (m == i || m == j || m == k || m == l) {
							continue;
						}
						if (result == array[code[i] - 'A'][0] - array[code[j] - 'A'][1] + array[code[k] - 'A'][2] - array[code[l] - 'A'][3] + array[code[m] - 'A'][4]) {
							cout << code[i] << code[j] << code[k] << code[l] << code[m] << endl;
							return;
						}
					}
				}
			}
		}
	}
	cout << "no solution" << endl;
}
