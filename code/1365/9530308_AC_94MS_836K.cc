#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

vector<int> prime;

void solve(const string& line);
void divide_number(int number);
void print_result(map<int, int>& result);
void get_prime();
bool is_prime(int n);

int main()
{
	get_prime();
	string line;
	while (getline(cin, line)) {
		if (line == "0") {
			break;
		}
		solve(line);
	}
	return 0;
}

void solve(const string& line)
{
	stringstream ss(line);
	int number = 1;
	int factor, exponent;
	while (ss >> factor >> exponent) {
		number *= pow(factor, exponent);
	}
	--number;

	divide_number(number);
}

void divide_number(int number)
{
	map<int, int> result;
	for (vector<int>::size_type i = 0; i != prime.size(); ++i) {
		if (number < prime[i]) {
			break;
		}

		while (number % prime[i] == 0) {
			number /= prime[i];
			++result[prime[i]];
		}
	}

	print_result(result);
}

void print_result(map<int, int>& result)
{
	for (map<int, int>::reverse_iterator riter = result.rbegin(); riter != result.rend(); ++riter) {
		cout << riter->first << ' ' << riter->second << ' ';
	}
	cout << endl;
}

void get_prime()
{
	for (int i = 2; i < 32768; ++i) {
		if (is_prime(i)) {
			prime.push_back(i);
		}
	}
}

bool is_prime(int n)
{
	int upper_bound = sqrt(n);
	for (int i = 2; i <= upper_bound; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
