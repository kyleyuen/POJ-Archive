#include <iostream>
#include <cmath>

using namespace std;
int solve(int m, int n);

int main()
{
    int m, n;
    while (cin >> m >> n) {
        if (m < n) {
            cout << solve(n, m) << endl;
        }
        else {
            cout << solve(m, n) << endl;
        }
    }
    
    return 0;
}

int solve(int m, int n)
{
    if (m == n) {
        return 1;
    }
    
    double a = (1 + sqrt(5.0)) / 2;
    int result = int((m - n) * a);
    
    if (result == n) {
        return 0;
    }
    else {
        return 1;
    }
}