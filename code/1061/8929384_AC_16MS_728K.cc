#include <iostream>

using namespace std;

struct Triple {
    long long d;
    long long x;
    long long y;
};

Triple result;

int euclid(long long a, long long b);
void extended_euclid(long long a, long long b);

int main()
{
    int x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    
    int a = m - n;
	int b = l;
	int c = y - x;
	int r = euclid(a,b);
	if (c % r) {
		cout << "Impossible\n" << endl;
    }
	else {
		extended_euclid(a, b);
		long long t = c * result.x / r / b;
		result.x = c * result.x / r - b * t;
		if (result.x < 0) {
			result.x += b;
        }
		cout << result.x << endl;
	}
    
    return 0;
}

int euclid(long long a, long long b)
{
    if (b == 0) {
        return a;
    }
    return euclid(b, a % b);
}

void extended_euclid(long long a, long long b)
{
    if (b == 0) {
        result.x = 1;
        result.y = 0;
    }
    else {
        extended_euclid(b, a % b);
        long long temp = result.x;
        result.x = result.y;
        result.y = temp - a / b * result.y;
    }
}
