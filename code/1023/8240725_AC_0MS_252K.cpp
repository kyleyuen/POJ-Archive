#include <iostream>
#include <string>

using namespace std;

void solve();

int main()
{
    int n;
    cin >> n;
    
    int count = 0;
    while (count != n) {
        solve();
        ++count;
    }
    
    return 0;
}

void solve()
{    
    __int64 k,n;
    string str;
    cin >> k >> str >> n;
    while(k--)
    {
        if (n & 1) {
            n -= str[k] == 'p' ? 1 : -1;
            str[k] = '1';
        }
        else {
            str[k] = '0';
        }
        n >>= 1;
    }
    if(n) {
        cout << "Impossible" << endl;
    }
    else {
        cout << str << endl;
    }
}