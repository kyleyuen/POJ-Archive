#include <iostream>
#include <string>
#include <vector>

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
    vector<int> coins(12, 0);
    int times = 0;
    string left, right;
    string conclusion;
    
    while (cin >> left >> right >> conclusion) {
        int lvalue = 1, rvalue = 1;
        if (conclusion == "up") {
            rvalue = 2;
        }
        else if (conclusion == "down") {
            lvalue = 2;
        }
        for (string::iterator iter = left.begin(); iter != left.end(); ++iter) {
            if (coins[*iter - 'A'] != 1) {
                coins[*iter - 'A'] = lvalue;
            }
        }
        for (string::iterator iter = right.begin(); iter != right.end(); ++iter) {
            if (coins[*iter - 'A'] != 1) {
                coins[*iter - 'A'] = rvalue;
            }
        }
        
        ++times;
        if (times == 3) {
            break;
        }
    }
    for (vector<int>::size_type n = 0; n != coins.size(); ++n) {
        if (coins[n] == 2) {
            cout << char('A' + n) << " is the counterfeit coin and it is light." << endl;
            break;
        }
    }
}
