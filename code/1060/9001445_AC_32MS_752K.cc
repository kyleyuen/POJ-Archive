#include <iostream>
#include <vector>

using namespace std;

void solve();
int get_degree(vector<int>& remainder);
void polynomials_multiplication(vector<int>& a, vector<int>& b, vector<int>& remainder);
bool polynomials_modular(vector<int>& remainder, int degree, vector<int>& c);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		solve();
	}

	return 0;
}

void solve()
{
	int degree;
	cin >> degree;
	vector<int> polynomial_a(degree);
	for (int i = degree - 1; i >= 0; --i) {
		cin >> polynomial_a[i];
	}
	cin >> degree;
	vector<int> polynomial_b(degree);
	for (int i = degree - 1; i >= 0; --i) {
		cin >> polynomial_b[i];
	}
	cin >> degree;
	vector<int> polynomial_c(degree);
	for (int i = degree - 1; i >= 0; --i) {
		cin >> polynomial_c[i];
	}

	vector<int> remainder(polynomial_a.size() + polynomial_b.size() - 1);
	polynomials_multiplication(polynomial_a, polynomial_b, remainder);
	degree = get_degree(remainder);
	while (polynomials_modular(remainder, degree, polynomial_c)) {
        degree = get_degree(remainder);
    }
	cout << degree + 1;
	for (int i = degree; i >= 0; --i) {
		cout << ' ' << remainder[i];
	}
	cout << endl;
}

void polynomials_multiplication(vector<int>& a, vector<int>& b, vector<int>& remainder)
{
	for (vector<int>::size_type i = 0; i != a.size(); ++i) {
		for (vector<int>::size_type j = 0; j != b.size(); ++j) {
			remainder[i + j] ^= a[i] & b[j];
		}
	}
}

bool polynomials_modular(vector<int>& remainder, int degree, vector<int>& c)
{
	if (degree < c.size() - 1) {
		return false;
	}

	int difference = degree - c.size() + 1;
	for (vector<int>::size_type i = 0; i != c.size(); ++i) {
		remainder[i + difference] ^= c[i];
	}
	return true;
}

int get_degree(vector<int>& remainder)
{
	for (int i = remainder.size() - 1; i >= 0; --i) {
		if (remainder[i] == 1) {
			return i;
		}
	}
	return 0;
}
