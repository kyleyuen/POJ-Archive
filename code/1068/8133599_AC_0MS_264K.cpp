#include <iostream>
#include <vector>

using namespace std;

vector<int> convert();

int main()
{
    int cases;
    int count = 0;
    cin >> cases;
    vector< vector<int> > output(cases);
    
    while (count != cases) {
        output[count] = convert();
        ++count;
    }
    
    for (vector<int>::size_type i = 0; i != output.size(); ++i) {
        vector<int>::size_type j = 0;
        for (; j != output[i].size() - 1; ++j) {
            cout << output[i][j] << ' ';
        }
        cout << output[i][j] << endl;
    }
    return 0;
}

vector<int> convert()
{
    int n;
    int nCount = 0;
    cin >> n;
    
    vector<int> parentheses(n * 2, 0);
    int num;   
    vector<int> rtn;
    
    while (nCount != n) {
        cin >> num;
        int count = 0;
        for (vector<int>::iterator iter = parentheses.begin(); iter != parentheses.end(); ++iter) {
            if (*iter == 0) {
                if (count == num) {
                    *iter = 1;
                    break;
                }
                ++count;
            }
        }
        ++nCount;
    }
        
    for (vector<int>::iterator iter = parentheses.begin(); iter != parentheses.end(); ++iter) {
        if (*iter == 1) {
            int c = 0;
            for (vector<int>::iterator it = iter - 1; ; --it) {
                if (*it == 0 || *it == 2) {
                    ++c;
                }
                if (*it == 0) {
                    *it = 2;
                    break;
                }
            }
            rtn.push_back(c);
        }
    }
    return rtn;
}