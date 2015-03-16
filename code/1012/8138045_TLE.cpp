#include <iostream>
#include <vector>

using namespace std;

int joseph(int n);

int main()
{
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << joseph(n) << endl;
    }
    return 0;
}

int joseph(int n)
{
    for (int m = n + 1; ; ++m) {
        vector<int> human(n * 2, 1);
        int sum = 2 * n;
        int count = 0;
        for (vector<int>::size_type i = 0; ; ++i) {
            if (sum == n) {
                return m;
            }
            if (i == human.size()) {
                i = 0;
            }
            if (human[i]) {
                ++count;
            }
            if (count == m) {
                if (i < n) {
                    break;
                }
                else {
                    human[i] = 0;
                    count = 0;
                    --sum;
                }
            }
        }
    }
}