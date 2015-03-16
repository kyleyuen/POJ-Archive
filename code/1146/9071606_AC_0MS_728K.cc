#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string line;
	while (cin >> line) {
		if (line == "#") {
			break;
		}
		
		if (next_permutation(line.begin(), line.end())) {
			cout << line << endl;
		}
		else {
			cout << "No Successor" << endl;
		}
	}
	return 0;
}