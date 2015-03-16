#include <iostream>
#include <vector>

using namespace std;

void solve();

int main()
{
    solve();
    return 0;
}

void solve()
{
    int line = 1;
    int array[6];
    
    while (cin >> array[0] >> array[1] >> array[2] >> array[3] >> array[4] >> array[5]) {
        if (array[0] == 0 && array[1] == 0 && array[2] == 0 && array[3] == 0 && array[4] == 0 && array[5] == 0) {
            break;
        }
        
        cout << "Collection #" << line << ":" << endl;
        ++line;
        
        int sum = 0;
        for (int i = 0; i != 6; ++i) {
            sum += (i + 1) * array[i];
        }        
        if (sum % 2 != 0) {
            cout << "Can't be divided." << endl;
            cout << endl;
            continue;
        }
        
        int target = sum / 2;
        vector<bool> marble(target + 1, false);
        for (int i = 0; i <= array[0]; ++i) {
            marble[i] = true;
        }
        for (int i = 1; i != 6; ++i) {
            for (int j = target; j >= 0; --j) {
                int increment = 0;
                for (int k = 1; k <= array[i]; ++k) {
                    increment += i + 1;
                    if (j + increment > target) {
                        break;
                    }
                    if (marble[j] && !marble[j + increment]) {
                        marble[j + increment] = true;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        if (marble[target]) {
            cout << "Can be divided." << endl;
        }
        else {
            cout << "Can't be divided." << endl;
        }
        cout << endl;
    }
}
