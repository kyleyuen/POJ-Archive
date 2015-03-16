#include <iostream>
#include <vector>

using namespace std;

int erosion(double x, double y);
const double pi = 3.1415926;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    vector<int> result(n);
    
    double x, y;
    while (count != n) {
        cin >> x >> y;
        result[count] = erosion(x, y);
        ++count;
    }
    
    for (int i = 0; i != n; ++i) {
        cout << "Property " << i + 1 << ": This property will begin eroding in year " << result[i] << '.' << endl;
    }
    
    cout << "END OF OUTPUT." << endl;
    return 0;
}

int erosion(double x, double y)
{
    double area = 100;
    int year = 1;
    
    double sum = x * x + y * y;
    while (sum > area / pi) {
        ++year;
        area += 100;
    }
    return year;
}