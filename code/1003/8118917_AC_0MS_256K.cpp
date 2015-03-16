#include <iostream>

using namespace std;

int number_of_cards(double c);

int main()
{
    double c;
    
    while (cin >> c) {
        if (c == 0.00) {
            break;
        }
        cout << number_of_cards(c) << " card(s)" << endl;
    }
    
    return 0;
}

int number_of_cards(double c)
{
    double n = 1;
    double sum = 0;
    
    while (sum < c) {
        ++n;
        sum += 1 / n;
    }
    return n - 1;
}
