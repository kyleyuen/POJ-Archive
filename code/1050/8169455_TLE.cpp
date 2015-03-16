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
        vector< vector<int> > submatrix;
        
        for (int j = 0; j != matrix.size(); ++j) {
            vector<int> line;
            
            for (int k = 0; k <= matrix.size() - i; ++k) {
                int val = 0;
                for (int l = 0; l != i; ++l) {
                    val += matrix[j][k + l];
                }
                line.push_back(val);
            }
            submatrix.push_back(line);
        }
        
        for (int m = 0; m <= matrix.size() - i; ++m) {
            for (int n = 1; n <= matrix.size(); ++n) {
                for (int p = 0; p != n; ++p) {
                    int val = 0;
                    for (int q = p; q != n; ++q) {
                        val += submatrix[q][m];
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