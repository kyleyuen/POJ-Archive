#include <iostream>
#include <vector>

using namespace std;
int circle(int a1, int a2, int a3, int day);

int main()
{
    int a1, a2, a3;
    int day;
    vector<int> result;
    
    while (cin >> a1 >> a2 >> a3 >> day) {
        if (a1 == -1 && a2 == -1 && a3 == -1 && day == -1) {
            break;
        }
        result.push_back(circle(a1, a2, a3, day));
    }
    for (vector<int>::size_type n = 0; n != result.size(); ++n) {
        cout << "Case " << n + 1 << ": the next triple peak occurs in " << result[n] << " days." << endl;
    }
    return 0;
}

int circle(int a1, int a2, int a3, int day)
{
    int p = a1, e = a2, i = a3;
    
    int rtn = (5544 * a1 + 14421 * a2 + 1288 * a3 - day) % (23 * 28 * 33);
    if (rtn <= 0) {
        return 21252 - day;
    }
    else {
        return rtn;
    }
}
