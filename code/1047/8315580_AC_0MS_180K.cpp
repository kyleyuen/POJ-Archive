#include <iostream>
#include <string>

using namespace std;

void solve();
string multiple(string& s, int i);
string single(string& s, int n);
string str_plus(string& lhs, string& rhs);

int main()
{
    solve();
    return 0;
}

void solve()
{
    string integer;
    while (cin >> integer) {
        string lhs = multiple(integer, integer.size() + 1);
        string rhs = string(integer.size(), '9');
        if (lhs == rhs) {
            cout << integer << " is cyclic" << endl;
        }
        else {
            cout << integer << " is not cyclic" << endl;
        }
    }
}

string multiple(string& s, int n)
{
    string result;
    if (10 <= n) {
        string a = single(s, n % 10);
        string b = single(s, n / 10) + "0";
        result = str_plus(b, a);
    }
    else {
        result = single(s, n);
    }
    if (result[0] == '0') {
        result.erase(result.begin());
    }
    return result;
}

string single(string& s, int n)
{
    string result(s);
    int carry = 0;
    for (string::reverse_iterator iter = result.rbegin(); iter != result.rend(); ++iter) {
        int num = (*iter - '0') * n;
        *iter = (num % 10) + carry + '0';
        carry = num / 10;
        if (*iter > '9') {
            *iter -= 10;
            ++carry;
        }
    }
    if (carry > 0) {
        string c(1, carry);
        result = c + result;
    }
    return result;
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