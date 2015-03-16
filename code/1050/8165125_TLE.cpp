#include <iostream>
#include <vector>

using namespace std;
int to_the_max(vector< vector<int> >& matrix);

int main()
{
    int width;
    cin >> width;
    vector< vector<int> > matrix;
    vector<int> line(width);
    int val;
    int count = 0;
    int turn = 0;
    
    while (cin >> val) {
        line[count] = val;
        ++count;
        if (count % width == 0) {
            matrix.push_back(line);
            count = 0;
            ++turn;
        }
        if (turn == width) {
            break;
        }
    }
    cout << to_the_max(matrix) << endl;
    
    return 0;
}

int to_the_max(vector< vector<int> >& matrix)
{
    int high = 0;
    for (int i = 1; i <= matrix.size(); ++i) {
        
        for (int j = 0; j != matrix.size(); ++j) {
            for (int k = 0; k <= matrix.size() - i; ++k) {
                
                for (int t = 1; t <= matrix.size() - j; ++t) {
                    int val = 0;
                    for (int m = 0; m != t; ++m) {
                        for (int n = 0; n != i; ++n) {
                            val += matrix[j + m][k + n];
                        }
                    }
                    if (val > high) {
                        high = val;
                    }
                }
            }
        }
    }
    return high;
}