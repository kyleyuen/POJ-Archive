#include <iostream>
#include <string>

using namespace std;

string str_plus(string& lhs, string& rhs);
void erase_prefix_zero(string& result);

int main()
{
	string result("0");
	string line;
	while (cin >> line) {
		if (line == "0") {
			break;
		}
		erase_prefix_zero(line);
		result = str_plus(result, line);
	}
	cout << result << endl;
}

string str_plus(string& lhs, string& rhs)
{
    string sum;
    if (lhs.size() >= rhs.size()) {
        sum = lhs;
    }
    else {
        sum = rhs;
    }

    bool carry_set(false);
    string::size_type n = sum.size() - 1;
    for (string::reverse_iterator liter = lhs.rbegin(), riter = rhs.rbegin(); liter != lhs.rend() && riter != rhs.rend(); ++liter, ++riter, --n) {
        sum[n] = *liter + *riter - '0';
    }
	for (string::size_type i = sum.size() - 1; i != 0; --i) {
		if (sum[i] > '9') {
			sum[i] -= 10;
			++sum[i - 1];
		}
	}
    if (sum[0] > '9') {
        sum[0] -= 10;
        sum = "1" + sum;
    }
    return sum;
}

void erase_prefix_zero(string& result)
{
	for (string::iterator iter = result.begin(); iter != result.end(); ++iter) {
		if (*iter != '0') {
			result.erase(result.begin(), iter);
			break;
		}
	}
}
