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
    int value;
    
    while (cin >> left >> right >> conclusion) {
        if (conclusion == "even") {
            value = 1;
        }
        else if (conclusion == "up") {
            value = 2;
        }
        for (string::iterator iter = left.begin(); iter != left.end(); ++iter) {
            if (coins[*iter - 'A'] != 1) {
                coins[*iter - 'A'] = value;
            }
        }
        for (string::iterator iter = right.begin(); iter != right.end(); ++iter) {
            if (coins[*iter - 'A'] != 1) {
                coins[*iter - 'A'] = value;
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