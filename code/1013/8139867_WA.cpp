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
    vector<string> judge(3);
    
    while (cin >> left >> right >> conclusion) {
        if ((conclusion == "up") || (conclusion == "down")) {
            judge[0] = left;
            judge[1] = right;
            judge[2] = conclusion;
        }
        if (conclusion == "even") {
            for (string::iterator iter = left.begin(); iter != left.end(); ++iter) {
                    coins[*iter - 'A'] = 1;
            }
            for (string::iterator iter = right.begin(); iter != right.end(); ++iter) {
                    coins[*iter - 'A'] = 1;
            }
        }
        
        ++times;
        if (times == 3) {
            break;
        }
    }
    
    bool mark = false;
    char c;
    for (string::size_type n = 0; n != judge[0].size(); ++n) {
        if (coins[judge[0][n] - 'A'] != 1) {
            c = judge[0][n];
            break;
        }
        if (coins[judge[1][n] - 'A'] != 1) {
            c = judge[1][n];
            mark = true;
            break;
        }
    }
    if (mark) {
        if ((judge[2] == "up" && !mark) || (judge[2] == "down" && mark)) {
            cout << c << " is the counterfeit coin and it is heavy." << endl;
        }
        else {
            cout << c << " is the counterfeit coin and it is light." << endl;
        }
    }
}