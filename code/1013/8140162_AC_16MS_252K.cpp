#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
void solve();
bool islight(vector<string>& judge, char c);
bool isheavy(vector<string>& judge, char c);

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
    set<char> coins;
    for (char c = 'A'; c != 'M'; ++c) {
        coins.insert(c);
    }
    
    int times = 0;
    string left, right;
    string conclusion;
    vector<string> judge;
    while (cin >> left >> right >> conclusion) {
        if (conclusion == "even") {
            for (string::size_type n = 0; n != left.size(); ++n) {
                coins.erase(left[n]);
                coins.erase(right[n]);
            }
        }
        else {
            judge.push_back(left);
            judge.push_back(right);
            judge.push_back(conclusion);
            for (char c = 'A'; c != 'M'; ++c) {
                if (!(left.find(c) || right.find(c))) {
                    coins.erase(c);
                }
            }
        }
        
        ++times;
        if (times == 3) {
            break;
        }
    }
    
    for (set<char>::iterator iter = coins.begin(); iter != coins.end(); ++iter) {
        if (islight(judge, *iter)) {
            cout << *iter << " is the counterfeit coin and it is light." << endl;
            break;
        }
        if (isheavy(judge, *iter)) {
            cout << *iter << " is the counterfeit coin and it is heavy." << endl;
            break;
        }
    }
}

bool islight(vector<string>& judge, char c)
{
    for (vector<string>::size_type n = 0; n != judge.size(); n += 3) {
        if (judge[n + 2] == "up") {
            if (judge[n + 1].find(c) == string::npos) {
                return false;
            }
        }
        if (judge[n + 2] == "down") {
            if (judge[n].find(c) == string::npos) {
                return false;
            }
        }
    }
    return true;
}

bool isheavy(vector<string>& judge, char c)
{
    for (vector<string>::size_type n = 0; n != judge.size(); n += 3) {
        if (judge[n + 2] == "up") {
            if (judge[n].find(c) == string::npos) {
                return false;
            }
        }
        if (judge[n + 2] == "down") {
            if (judge[n + 1].find(c) == string::npos) {
                return false;
            }
        }
    }
    return true;
}
