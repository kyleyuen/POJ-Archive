#include <iostream>

using namespace std;

int array[21][21][21];

void initial();
int solve(int a, int b, int c);

int main()
{
	initial();
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << solve(a, b, c) << endl;;
	}
	return 0;
}

void initial()
{
	for (int a = 0; a <= 20; ++a) {
		for (int b = 0; b <= 20; ++b) {
			for (int c = 0; c <= 20; ++c) {
			    if (a == 0 || b == 0 || c== 0) {
                    array[a][b][c] = 1;
                    continue;
			    }
				if (a < b && b < c) {
					array[a][b][c] = array[a][b][c - 1] + array[a][b - 1][c - 1] - array[a][b - 1][c];
				}
				else {
					array[a][b][c] = array[a - 1][b][c] + array[a - 1][b - 1][c] + array[a - 1][b][c - 1] - array[a - 1][b - 1][c - 1];
				}
			}
		}
	}
}

int solve(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return array[20][20][20];
	}
	return array[a][b][c];
}
