#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double vs, r, c;
    cin >> vs >> r >> c;
    
    int count;
    cin >> count;
    for (int i = 0; i != count; ++i) {
        double omega;
        cin >> omega;
        printf("%.3lf\n", c * r * omega * vs / sqrt(1 + c*r*omega * c*r*omega));
    }
    
    return 0;
}
