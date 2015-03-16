#include <iostream>
#include <string>

using namespace std;

string power(string& r, int n);
string str_plus(string& lhs, string& rhs);
string str_times(string& lhs, string& rhs);

int main()
{
    string r;
    int n;
    
    while (cin >> r >> n) {
        for (string::size_type i = r.size() - 1; i != 0; --i) {
            if (r[i] != '0') {
                r.erase(i + 1, r.size() - i - 1);
                break;
            }
        }
        cout << power(r, n) << endl;
    }
    return 0;
}

string power(string& r, int n)
{
    int precision = 0;
    for (string::size_type i = 0; i != r.size(); ++i) {
        if (r[i] == '.') {
            r.erase(i, 1);
            precision = (r.size() - i) * n;
            break;
        }
    }
    
    string sum(r);
    while (--n) {
        sum = str_times(sum, r);
    }
    if (precision != 0) {
        sum.insert(sum.size() - precision, 1, '.');
    }
    if (sum.find('.') == 1 && sum[0] == '0') {
        sum.erase(0, 1);
    }
    return sum;
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

string str_times(string& lhs, string& rhs)
{
    string sum("0");
    for (string::size_type n = 0; n != rhs.size(); ++n) {
        int single = rhs[rhs.size() - n - 1] - '0';
        string turn(lhs);
        char carry_set = 0;
        for (string::reverse_iterator iter = lhs.rbegin(), iturn = turn.rbegin(); iter != lhs.rend(); ++iter, ++iturn) {
            *iturn = (*iter - '0') * single; 
            if (carry_set != 0) {
                *iturn += carry_set;
                carry_set = 0;
            }           
            if (*iturn > 9) {
                carry_set = *iturn / 10;
                *iturn %= 10;
            }
            *iturn += '0';
        }
        if (carry_set != 0) {
            turn = string(1, carry_set + '0') + turn;
        }
        turn += string(n, '0');
        sum = str_plus(sum, turn);
    }
    return sum;
}