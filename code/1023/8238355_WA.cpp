#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <limits>
#include <cstdlib>

using namespace std;

void solve();
void construct();
void convert(set<int>& bit, vector<long long>& lower_bound, vector<long long>& upper_bound);

vector<long long> binary;

int main()
{
    int n;
    cin >> n;
    
    construct();
    int count = 0;
    while (count != n) {
        solve();
        ++count;
    }
    
    return 0;
}


void solve()
{
    int width;
    cin >> width;
    string s;
    cin >> s;
    
    int temp = width;
    set<int> bit;
    for (string::iterator iter = s.begin(); iter != s.end(); ++iter) {
        --temp;
        if (*iter == 'p') {
            bit.insert(temp);
        }
    }
    
    bool upper_judge = false;
    bool lower_judge = false;
    if (width == 64) {
        if (bit.size() == 64) {
            upper_judge = true;
            --width;
        }
        if (bit.size() == 0) {
            lower_judge = true;
            --width;
        }
    }
    vector<long long> upper_bound;
    vector<long long> lower_bound;
    long long upper = 0;
    long long lower = 0;
    for (int i = 0; i != width; ++i) {
        if (bit.find(i) == bit.end()) {
            lower -= binary[i];               
        }
        else {
            upper += binary[i];
        }
        upper_bound.push_back(upper);
        lower_bound.push_back(lower);
    }
    if (upper_judge) {
        upper_bound.push_back(numeric_limits<long long>::max());
    }
    if (lower_judge) {
        lower_bound.push_back(numeric_limits<long long>::min());
    }
    
    convert(bit, lower_bound, upper_bound);
}

void construct()
{
    long long n = 1;
    binary.push_back(n);
    for (int i = 0; i != 63; ++i) {
        n *= 2;
        binary.push_back(n);
    }
}

void convert(set<int>& bit, vector<long long>& lower_bound, vector<long long>& upper_bound)
{
    long long num;
    cin >> num;
    if (num < lower_bound[lower_bound.size() - 1] || upper_bound[upper_bound.size() - 1] < num) {
        cout << "Impossible" << endl;
        return;
    }
    
    vector<int> result;
    for (vector<long long>::size_type i = upper_bound.size() - 1; i != 0; --i) {
        if (bit.find(i) == bit.end()) {
            if (num < lower_bound[i - 1]) {
                result.push_back(1);
                num += binary[i];
            }
            else {
                result.push_back(0);
            }
        }
        else {
            if (upper_bound[i - 1] < num) {
                result.push_back(1);
                num -= binary[i];
            }
            else {
                result.push_back(0);
            }                
        }
    }
    if (num == 0) {
        result.push_back(0);
    }
    else {
        result.push_back(1);
    }
    
    for (vector<int>::size_type i = 0; i != result.size(); ++i) {
        cout << result[i];
    }
    cout << endl;
}