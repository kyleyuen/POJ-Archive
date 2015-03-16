#include <iostream>
#include <string>
#include <map>

using namespace std;

string& convert(string& s);

int main()
{
    int num;
    map<string, int> dic;
     
    int count = 0;
    cin >> num;
    while (num != count) {
        string tel;
        cin >> tel;
        convert(tel);
        ++dic[tel];
        ++count;
    }
    
    for (map<string, int>::iterator iter = dic.begin(); iter != dic.end(); ++iter) {
        if (iter->second != 1) {
            cout << iter->first << ' ' << iter->second << endl;
        }
    }
    return 0;
}

string& convert(string& s)
{
    for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
        switch (*iter) {
            case '-':
                iter = s.erase(iter);
                --iter;
                break;
            case 'A': case 'B': case 'C':
                *iter = '2';
                break;
            case 'D': case 'E': case 'F': 
                *iter = '3';
                break;
            case 'G': case 'H': case 'I': 
                *iter = '4';
                break;
            case 'J': case 'K': case 'L': 
                *iter = '5';
                break;
            case 'M': case 'N': case 'O': 
                *iter = '6';
                break;
            case 'P': case 'R': case 'S': 
                *iter = '7';
                break;
            case 'T': case 'U': case 'V': 
                *iter = '8';
                break;
            case 'W': case 'X': case 'Y': 
                *iter = '9';
                break;
            default:
                ;
        }
    }
    s.insert(3, 1, '-');
    return s;
}
