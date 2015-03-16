#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void construct(vector<int>& vec);
void solve();
int search(int val);
int number(int n);

vector<int> vec;

int main()
{
    int n;
    cin >> n;
    
    construct(vec);
    int count = 0;
    while (count != n) {
        solve();
        ++count;
    }

    return 0;
}

void construct(vector<int>& vec)
{
    int bit = 0;
    int n = 0;
    for (int i = 0; n <= 2147233248; n += bit) {
        vec.push_back(n);
        ++i;
        if (9999 < i) {
            bit += 5;
        }
        else if (999 < i && i <= 9999) {
            bit += 4;
        }
        else if (99 < i && i <= 999) {
            bit += 3;
        }
        else if (9 < i && i <= 99){
            bit += 2;
        }
        else {
            ++bit;
        }
    }
    vec.push_back(n); 
}

void solve()
{
    int val;
    cin >> val;
    int result = val - search(val);
    cout << number(result) << endl;
}

int search(int val)
{
    vector<int>::size_type begin = 0;
    vector<int>::size_type end = vec.size();
    
    while (1 < end - begin) {
        vector<int>::size_type middle = (begin + end) / 2;
        if (vec[middle] < val) {
            begin = middle;
        }
        else {
            end = middle;
        }
    }
    return vec[begin];
}

int number(int n)
{
    int num;
    int remain;
    if (38890 <= n) {
        num = (n - 38890) / 5 + 10000;
        remain = (n - 38890) % 5;
    }
    else if (2890 <= n && n < 38890) {
        num = (n - 2890) / 4 + 1000;
        remain = (n - 2890) % 4;
    }
    else if (190 <= n && n < 2890) {
        num = (n - 190) / 3 + 100;
        remain = (n - 190) % 3;
    }
    else if (10 <= n && n < 190) {
        num = (n - 10) / 2 + 10;
        remain = (n - 10) % 2;
    }
    else {
        return n;
    }
    
    stringstream ss;
    string str;
    ss << num;
    ss >> str;
    return str[remain] - '0';
}