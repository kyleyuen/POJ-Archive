#include <iostream>
#include <string>

using namespace std;

int solve();
int get_lower_bound(const string& str);
int get_value(const string& str, int base);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		cout << solve() << endl;
	}
	return 0;
}

int solve()
{
	string p, q, r;
	cin >> p >> q >> r;

    int lower_bound = get_lower_bound(p);
    if (lower_bound < get_lower_bound(q)) {
        lower_bound = get_lower_bound(q);
    }
    if (lower_bound < get_lower_bound(r)) {
        lower_bound = get_lower_bound(r);
    }

	for (int i = lower_bound + 1; i <= 36; ++i) {
		if (get_value(p, i) * get_value(q, i) == get_value(r, i)) {
			return i;
		}
	}
	return 0;
}

int get_lower_bound(const string& str)
{
    int result = 0;
    for (string::size_type i = 0; i != str.size(); ++i) {
        if (result < str[i] - '0') {
            result = str[i] - '0';
        }
    }
    return result;
}

int get_value(const string& str, int base)
{
	int result = 0;
	for (string::size_type i = 0; i != str.size(); ++i) {
		result = result * base + str[i] - '0';
	}
	return result;
}
