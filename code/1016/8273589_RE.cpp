#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(string& number_str, int& length);
void convert(string& s);
void print_answer(int i, int length);

int main()
{
    string s;

    while (cin >> s) {
        if (s == "-1") {
            break;
        }
        int length = 0;
        cout << s;
        int result = solve(s, length);
        print_answer(result, length);
    }

    return 0;
}

int solve(string& number_str, int& length)
{
    vector<string> record;
    string s(number_str);

    record.push_back(s);
    for (int i = 0; ; ++i) {
        if (i == 15) {
            return 4;
        }

        convert(s);
        if (i == 0 && s == record[0]) {
            return 1;
        }
        if (s == record[record.size() - 1]) {
            length = i;
            return 2;
        }
        for (vector<string>::size_type n = 1; n != record.size(); ++n) {
            if (s == record[n]) {
                length = record.size() - n;
                return 3;
            }
        }
        record.push_back(s);
    }

}

void print_answer(int i, int length)
{
    switch (i) {
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

void convert(string& s)
{
    vector<int> letter(10, 0);

    for (string::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
        ++letter[*iter - '0'];
    }
    s.clear();
    for (vector<int>::size_type n = 0; n != letter.size(); ++n) {
        if (letter[n] != 0) {
            s.push_back('0' + letter[n]);
            s.push_back('0' + n);
        }
    }
}