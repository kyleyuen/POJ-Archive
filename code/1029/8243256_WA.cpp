#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void solve();

int main()
{    
    solve();
    
    system("pause");
    return 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    set<int> identifier;
    for (int i = 1; i <= n; ++i) {
        identifier.insert(i);
    }

    map<int, int> suspect;
    while (k--) {
        int count;
        cin >> count;
        
        int val;
        set<int> left_pan;
        set<int> right_pan;
        for (int i = 0; i != count; ++i) {
            cin >> val;
            left_pan.insert(val);
        }
        for (int i = 0; i != count; ++i) {
            cin >> val;
            right_pan.insert(val);
        }
        
        char c;
        cin >> c;
        vector<int> container;
        switch (c) {
            case '<':
            case '>':
                for (set<int>::iterator iter = identifier.begin(); iter != identifier.end(); ++iter) {
                    if (left_pan.find(*iter) == left_pan.end() && right_pan.find(*iter) == right_pan.end()) {
                        container.push_back(*iter);
                    }
                    else {
                        ++suspect[*iter];
                    }
                }
                break;
            case '=':
                for (set<int>::iterator iter = left_pan.begin(); iter != left_pan.end(); ++iter) {
                    container.push_back(*iter);
                }
                for (set<int>::iterator iter = right_pan.begin(); iter != right_pan.end(); ++iter) {
                    container.push_back(*iter);
                }
                break;
            default:
                ;
        }
        for (vector<int>::iterator iter = container.begin(); iter != container.end(); ++iter) {
            identifier.erase(*iter);
        }
    }
    
    if (identifier.size() == 1) {
        cout << *identifier.begin() << endl;
    }
    else {
        int val;
        int max = 0;
        for (map<int, int>::iterator iter = suspect.begin(); iter != suspect.end(); ++iter) {
            if (max < iter->second) {
                max = iter->second;
                val = iter->first;
            }
        }
        cout << val << endl;
    }
}