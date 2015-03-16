#include <iostream>
#include <vector>

using namespace std;

int solve(int n);

int main()
{
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << solve(n) << endl;
    }
    return 0;
}

int solve(int n)
{
    int target = 0;
    for (int i = 1; ; ++i) {
        int result = 0;
        for (int j = 2; j < n; ++j) {
            result = (result+i) % j;
        }

        if (result == target) {
            return i;
        }
    }
}
