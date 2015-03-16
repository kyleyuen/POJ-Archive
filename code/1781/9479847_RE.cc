#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve(const string& line);
int calculate(int n);
string toBinary(int n);
void shift_by_left(string& binary);
int toDecimal(const string& binary);

int main()
{
    string line;
    while (cin >> line) {
        if (line == "") {
            break;
        }
        cout << solve(line) << endl;
    }
    return 0;
}

int solve(const string& line)
{
	int n = (line[0] - '0') * 10 + (line[1] - '0');
	for (char i = '0'; i < line[3]; ++i) {
		n *= 10;
	}

	return calculate(n);
}

int calculate(int n)
{
	string binary = toBinary(n);
	shift_by_left(binary);
	return toDecimal(binary);
}

string toBinary(int n)
{
	string result;
	while (n > 0) {
		result.push_back(n % 2 + '0');
		n /= 2;
	}
	reverse(result.begin(), result.end());
	return result;
}

void shift_by_left(string& binary)
{
	char first = binary[0];
	for (string::size_type i = 0; i != binary.size() - 1; ++i) {
		binary[i] = binary[i + 1];
	}
	binary[binary.size() - 1] = first;
}

int toDecimal(const string& binary)
{
	int result = 0;
	for (string::const_iterator iter = binary.begin(); iter != binary.end(); ++iter) {
		result = result * 2 + (*iter - '0');
	}
	return result;
}
