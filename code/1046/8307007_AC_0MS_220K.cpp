#include <iostream>

using namespace std;
void solve();

int main()
{
    solve();
    return 0;
}

void solve()
{
    int remain[16][3];
    for (int i = 0; i != 16; ++i) {
        for (int j = 0; j != 3; ++j) {
            cin >> remain[i][j];
        }
    }

    int test[3];
    while (cin >> test[0] >> test[1] >> test[2]) {
        if (test[0] == -1 && test[1] == -1 && test[2] == -1) {
            break;
        }

        int record;
        int min = 0x7FFFFFFF;
        for (int i = 0; i != 16; ++i) {
            int temp = 0;
            for (int j = 0; j != 3; ++j) {
                temp += (test[j] - remain[i][j]) * (test[j] - remain[i][j]);
            }
            if (temp < min) {
                min = temp;
                record = i;
            }
        }
        cout << '(' << test[0] << ',' << test[1] << ',' << test[2] << ')';
        cout << " maps to ";
        cout << '(' << remain[record][0] << ',' << remain[record][1] << ',' << remain[record][2] << ')' << endl;
    }
}