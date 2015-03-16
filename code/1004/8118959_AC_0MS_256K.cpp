#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    double money;
    double total = 0;
    
    while (count != 12) {
        cin >> money;
        total += money;
        ++count;
    }
    
    cout << "$" << total / count << endl;
    return 0;
}