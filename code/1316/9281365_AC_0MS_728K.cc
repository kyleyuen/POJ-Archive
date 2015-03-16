#include <iostream>
#include <vector>

using namespace std;

void solve();

int main()
{
	solve();
	return 0;
}

void solve()
{
	vector<bool> number(10001, true);
	for (int i = 0; i != 10; ++i)
	for (int j = 0; j != 10; ++j)
	for (int k = 0; k != 10; ++k)
	for (int l = 0; l != 10; ++l)
		number[i * 1001 + j *101 + k * 11 + l * 2] = false;

	for (int i = 0; i <= 10000; ++i) {
		if (number[i]) {
			cout << i << endl;
		}
	}
}
