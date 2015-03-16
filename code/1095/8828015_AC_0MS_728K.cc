#include <iostream>
#include <vector>
#include <cstdlib>

#define NUMBER_LIMITS 20
using namespace std;


void solve(int n);
void construct_catalan_number();
void construct_number_list();

long long catalan_number[NUMBER_LIMITS];
long long number_list[NUMBER_LIMITS];

int main()
{
    int n;
    construct_catalan_number();
    construct_number_list();

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        solve(n);
        cout << endl;
    }

    return 0;
}

void solve(int n)
{
    if(n == 1) {
        cout << 'X';
        return;
    }

    int node = 0;
    while(true) {
        ++node;
        if(number_list[node] >= n) {
            --node;
            break;
        }
    }
    n -= number_list[node];
    
    int left_subtree;
    for (left_subtree = 0; left_subtree <= node; ++left_subtree) {
        int temp = catalan_number[left_subtree] * catalan_number[node - left_subtree];
        if (temp >= n) {
            break;
        }
        n -= temp;
    }
    
    if(left_subtree != 0) {
        cout << '(';
        solve(number_list[left_subtree - 1] + 1 + (n - 1) / catalan_number[node - left_subtree]);
        cout << ')';
    }
    cout << 'X';
    if(left_subtree != node) {
        cout << '(';
        solve(number_list[node - left_subtree - 1] + 1 + (n - 1) % catalan_number[node - left_subtree]);
        cout << ')';
    }
}

void construct_catalan_number()
{
    catalan_number[0] = 1;
    for (int i = 1; i != NUMBER_LIMITS; ++i) {
        catalan_number[i] = catalan_number[i - 1] * 2 * (2 * i - 1) / (i + 1);
    }
}

void construct_number_list()
{
    number_list[0] = 0;
    for (int i = 1; i != NUMBER_LIMITS; ++i) {
        number_list[i] = catalan_number[i] + number_list[i - 1];
    }
}
