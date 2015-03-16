#include <iostream>
#include <set>
#include <vector>
#include <cstdlib>

using namespace std;

int solve();
int judge(set<int>& identifier, vector< set<int> >& left_pans, vector< set<int> >& right_pans, vector<char>& results);
bool islight(int n, set<int>& left_pan, set<int>& right_pan, char result);
bool isheavy(int n, set<int>& left_pan, set<int>& right_pan, char result);

int main()
{    
    cout << solve() << endl;
    
    return 0;
}

int solve()
{
    int n, k;
    cin >> n >> k;
    set<int> identifier;
    for (int i = 1; i <= n; ++i) {
        identifier.insert(i);
    }

    vector< set<int> > left_pans;
    vector< set<int> > right_pans;
    vector<char> results;
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
        
        char result;
        cin >> result;
        vector<int> container;
        switch (result) {
            case '<':
            case '>':
                for (set<int>::iterator iter = identifier.begin(); iter != identifier.end(); ++iter) {
                    if (left_pan.find(*iter) == left_pan.end() && right_pan.find(*iter) == right_pan.end()) {
                        container.push_back(*iter);
                    }
                }
                left_pans.push_back(left_pan);
                right_pans.push_back(right_pan);
                results.push_back(result);
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
        return *identifier.begin();
    }
    else {
        return judge(identifier, left_pans, right_pans, results);
    }
}

int judge(set<int>& identifier, vector< set<int> >& left_pans, vector< set<int> >& right_pans, vector<char>& results)
{
    int count = 0;
    int n;
    bool light = false;
    bool heavy = false;
    for (set<int>::iterator iter = identifier.begin(); iter != identifier.end(); ++iter) {
        bool note = false;
        for (int i = 0; i != results.size(); ++i) {
            bool l = islight(*iter, left_pans[i], right_pans[i], results[i]);
            bool h = isheavy(*iter, left_pans[i], right_pans[i], results[i]);
            if (l) {
                light = true;
            }
            if (h) {
                heavy = true;
            }
            if (!(l || h)) {
                note = false;
                break;
            }
            else {
                note = true;
            }
        }
        if (note && !(light && heavy)) {
            ++count;
            n = *iter;
        }
        light = false;
        heavy = false;
    }
    
    if (count == 1) {
        return n;
    }
    else {
        return 0;
    }
}

bool islight(int n, set<int>& left_pan, set<int>& right_pan, char result)
{
    if (result == '<' && left_pan.count(n)) {
        return true;
    }
    if (result == '>' && right_pan.count(n)) {
        return true;
    }
    return false;
}

bool isheavy(int n, set<int>& left_pan, set<int>& right_pan, char result)
{
    if (result == '>' && left_pan.count(n)) {
        return true;
    }
    if (result == '<' && right_pan.count(n)) {
        return true;
    }
    return false;
}