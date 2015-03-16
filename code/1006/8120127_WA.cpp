#include <iostream>
#include <vector>

using namespace std;
int circle(int a1, int a2, int a3, int day);

int main()
{
    int a1, a2, a3;
    int day;
    int count = 1;
    
    while (cin >> a1 >> a2 >> a3 >> day) {
        if (a1 == -1 && a2 == -1 && a3 == -1 && day == -1) {
            break;
        }
        cout << "Case " << count << ": the next triple peak occurs in " << circle(a1, a2, a3, day) << " days." << endl;
        ++count;
    }
    return 0;
}

int circle(int a1, int a2, int a3, int day)
{
    int p = a1, e = a2, i = a3;
    
    if (a1 == 0 && a2 == 0 && a3 == 0) {
        return 21252 - day;
    }
    while (true) {
        if (p == e && e == i && i == p) {
            return p - day;
        }
        if (p < e || p < i) {
            p += 23;
        }
        if (e < i || e < p) {
            e += 28;
        }
        if (i < p || i < e) {
            i += 33;
        }
    }
}
