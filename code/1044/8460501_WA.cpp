#include <iostream>

using namespace std;
int solve(int input_cases);
bool judge(int year, int *p);

int main()
{
    int input_cases;
    for (int i = 1; cin >> input_cases; ++i) {
        if (input_cases == 0) {
            break;
        }
        
        cout << "Case #" << i << ':' << endl;
        int result = solve(input_cases);
        if (result == 0) {
            cout << "Unknown bugs detected." << endl;
        }
        else {
            cout << "The actual year is " << result << endl;
        }
        cout << endl;
    }
    return 0;
}

int solve(int input_cases)
{
    int bug_years[20][3];
    for (int i = 0; i != input_cases; ++i) {
        cin >> bug_years[i][0] >> bug_years[i][1] >> bug_years[i][2];
    }
    
    for (int year = bug_years[0][0]; year < 10000; year += bug_years[0][2] - bug_years[0][1]) {
        bool flag = true;
        for (int i = 1; i != input_cases; ++i) {
            if (!judge(year, bug_years[i])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return year;
        }
    }
    return 0;
}

bool judge(int year, int *p)
{
    for (int i = p[0]; i < 10000; i += p[2] - p[1]) {
        if (i == year) {
            return true;
        }
    }
    return false;
}