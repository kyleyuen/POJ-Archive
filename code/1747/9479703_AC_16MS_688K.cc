#include <iostream>

using namespace std;

void solve(int n);

int main()
{
	int n;
    cin >> n;
    solve(n);
    cout << endl;
    return 0;
}

void solve(int n)
{
    if (n == 1) {
        cout << "((A0|B0)|(A0|B0))";
        return;
    }
    else {
        cout << "((A" << n - 1 << "|B" << n - 1 << ")|(";
    }
    solve(n - 1);
    cout << "|((A" << n - 1 << "|A" << n - 1 << ")|(B" << n - 1 << "|B" << n - 1 << "))))";
}
