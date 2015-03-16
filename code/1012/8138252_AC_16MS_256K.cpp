#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec(14);
    vec[1] = 2;
    vec[2] = 7;
    vec[3] = 5;
    vec[4] = 30;
    vec[5] = 169;
    vec[6] = 441;
    vec[7] = 1872;
    vec[8] = 7632;
    vec[9] = 1740;
    vec[10] = 93313;
    vec[11] = 459901;
    vec[12] = 1358657;
    vec[13] = 2504881;
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << vec[n] << endl;
    }
    return 0;
}