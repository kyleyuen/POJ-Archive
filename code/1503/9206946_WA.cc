#include <iostream>
#include <string>

using namespace std;

string str_plus(string& lhs, string& rhs);

int main()
{
	string result("0");
	string line;
	while (cin >> line) {
		if (line == "0") {
			break;
		}
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
        if (carry_set) {
            ++sum[n];
            carry_set = false;
        }
        if ((n != 0) && (sum[n] > '9')) {
            sum[n] -= 10;
            carry_set = true;
        }
    }
    if (carry_set) {
        ++sum[n];
    }
    if (sum[0] > '9') {
        sum[0] -= 10;
        sum = "1" + sum;
    }
    return sum;
}
