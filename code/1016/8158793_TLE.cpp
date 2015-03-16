#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void solve(string& s);
string convert(const string& s);
string to_string(int n);

int main()
{
    string s;    
    while (cin >> s) {
        if (s == "-1") {
            break;
        }
        else {
            solve(s);
        }
    }
    
    return 0;
}

void solve(string& s)
{
    vector<string> record(1, s);
    int result = 0;
    int length = 0;
    bool jump_out = false;
    
    for (int i = 0; ; ++i) {
        if (i == 15) {
            result = 4;
            break;
        }
        
        s = convert(s);
        if (i == 0 && s == record[0]) {
            result = 1;
            break;
        }
        
        for (vector<string>::size_type n = 0; n != record.size(); ++n) {
            if (s == record[n]) {
                if (n == record.size() - 1) {
                    length = record.size() - 1;
                    result = 2;
                }
                else {
                    length = record.size() - n;
                    result = 3;
                }
                
                jump_out = true;
                break;
            }
        }
        if (jump_out) {
            break;
        }
        
        record.push_back(s);
    }
    
    cout << record[0];
    switch (result) {
        case 1:
            cout << " is self-inventorying" << endl;
            break;
        case 2:
            cout << " is self-inventorying after " << length << " steps" << endl;
            break;
        case 3:
            cout << " enters an inventory loop of length " << length << endl;
            break;
        case 4:
            cout << " can not be classified after 15 iterations" << endl;
            break;
        default:
            ;
    }
}

string convert(const string& s)
{
    string result;
    for (char c = '0'; c <= '9'; ++c) {
        char count = 0;
        for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
            if (*iter == c) {
                ++count;
            }
        }
        if (count != 0) {
            string temp = to_string(count);
            result += temp;
            result.push_back(c);
        }
    }
    return result;
}

string to_string(int n)
{
    string result;
    stringstream ss;
    ss << n;
    ss >> result;
    return result;
}