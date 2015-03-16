#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void solve();
void erase_prefix_zero(string& str);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		solve();
	}
	return 0;
}

void solve()
{
	string lhs, rhs;
	cin >> lhs >> rhs;
	reverse(lhs.begin(), lhs.end());
	reverse(rhs.begin(), rhs.end());

	int a, b;
	stringstream ss;
	ss << lhs;
	ss >> a;
	ss.clear();
	ss << rhs;
	ss >> b;
	ss.clear();

	ss << a + b;
	string result;
	ss >> result;
	reverse(result.begin(), result.end());
	erase_prefix_zero(result);
	cout << result << endl;
}

void erase_prefix_zero(string& str)
{
    string::iterator iter = str.begin();
    while (iter != str.end()) {
        if (*iter != '0') {
            break;
        }
        ++iter;
    }
    str.erase(str.begin(), iter);
}
