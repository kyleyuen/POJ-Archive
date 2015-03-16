#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(int key, string& line);

int main()
{
	int key;
	while (cin >> key) {
		if (key == 0) {
			break;
		}
		string line;
		cin >> line;
		solve(key, line);
	}
	return 0;
}

void solve(int key, string& line)
{
	int length = line.size();
	vector<int> cipher(length);
	for (int i = 0; i != length; ++i) {
		if (line[i] == '_') {
			cipher[i] = 0;
		}
		else if (line[i] == '.') {
			cipher[i] = 27;
		}
		else {
			cipher[i] = line[i] - 'a' + 1;
		}
	}

	vector<int> plain(length);
	for (int i = 0; i != length; ++i) {
		plain[key * i % length] = (cipher[i] + i) % 28;
	}
	for (int i = 0; i != length; ++i) {
        if (plain[i] == 0) {
			line[i] = '_';
		}
		else if (plain[i] == 27) {
			line[i] = '.';
		}
		else {
			line[i] = 'a' + plain[i] - 1;
		}
	}
	cout << line << endl;
}
