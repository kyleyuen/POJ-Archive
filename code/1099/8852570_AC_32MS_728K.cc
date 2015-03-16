#include <iostream>
#include <vector>

using namespace std;

void solve(int dimention);

int main()
{
    int counter = 1;
    int dimention;
    while (cin >> dimention) {
        if (dimention == 0) {
            break;
        }
        cout << "Case " << counter << ':' << endl << endl;
        solve(dimention);
        cout << endl;
        ++counter;
    }
    
    return 0;
}

void solve(int dimention)
{
    vector< vector<char> > figure(4 * dimention - 3, vector<char>(4 * dimention + 1, ' '));
    for (int i = 0; i != dimention; ++i) {
        for (int j = 0; j != dimention; ++j) {
            int code;
            cin >> code;
            switch (code) {
            case -1:
                figure[i * 4 - 2][j * 4 + 2] = 'H';
                figure[i * 4 - 1][j * 4 + 2] = '|';
                figure[i * 4][j * 4 + 2] = 'O';
                figure[i * 4 + 1][j * 4 + 2] = '|';
                figure[i * 4 + 2][j * 4 + 2] = 'H';
                break;
            case 0:
                figure[i * 4][j * 4 + 2] = 'O';
                if (i * 4 - 2 > 0 && figure[i * 4 - 2][j * 4 + 2] == ' ') {
                    figure[i * 4 - 2][j * 4 + 2] = 'H';
                    figure[i * 4 - 1][j * 4 + 2] = '|';
                }
                else {
                    figure[i * 4 + 1][j * 4 + 2] = '|';
                    figure[i * 4 + 2][j * 4 + 2] = 'H';
                }
                
                if (figure[i * 4][j * 4] == ' ') {
                    figure[i * 4][j * 4] = 'H';
                    figure[i * 4][j * 4 + 1] = '-';
                }
                else {
                    figure[i * 4][j * 4 + 3] = '-';
                    figure[i * 4][j * 4 + 4] = 'H';
                }
                break;
            case 1:
                figure[i * 4][j * 4] = 'H';
                figure[i * 4][j * 4 + 1] = '-';
                figure[i * 4][j * 4 + 2] = 'O';
                figure[i * 4][j * 4 + 3] = '-';
                figure[i * 4][j * 4 + 4] = 'H';
                break;
            default:
                break;
            }
        }
    }
    
    for (int i = 0; i != 4 * dimention + 3; ++i) {
        cout << '*';
    }
    cout << endl;
    for (int i = 0; i != 4 * dimention - 3; ++i) {
        cout << '*';
        for (int j = 0; j != 4 * dimention + 1; ++j) {
            cout << figure[i][j];
        }
        cout << '*' << endl;
    }
    for (int i = 0; i != 4 * dimention + 3; ++i) {
        cout << '*';
    }
    cout << endl;
}
    
