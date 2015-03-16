#include <iostream>
#include <vector>

using namespace std;

int solve();
int gene_function(char c);
int gene_function(char a, char b);

int main()
{
    int number;
    cin >> number;
    for (int i = 0; i != number; ++i) {
        cout << solve() << endl;
    }
    
    return 0;
}

int solve()
{
    //获取第一组基因序列 
    char str_a[101] = { '\0' };
    int length_a;
    cin >> length_a;
    for (int i = 1; i <= length_a; ++i) {
        cin >> str_a[i];
    }
    
    //获取第二组基因序列 
    char str_b[101] = { '\0' };
    int length_b;
    cin >> length_b;
    for (int i = 1; i <= length_b; ++i) {
        cin >> str_b[i];
    }
    
    //初始化 
    int function[101][101];
    function[0][0] = 0;
    for (int i = 1; i <= length_a; ++i) {
        function[i][0] = function[i - 1][0] + gene_function(str_a[i]);
    }
    for (int j = 1; j <= length_b; ++j) {
        function[0][j] = function[0][j - 1] + gene_function(str_b[j]);
    }
    //自底向上动态规划 
    for (int i = 1; i <= length_a; ++i) {
        for (int j = 1; j <= length_b; ++j) { 
            int max = function[i - 1][j - 1] + gene_function(str_a[i], str_b[j]);
            if (max < function[i][j - 1] + gene_function(str_b[j])) {
                max = function[i][j - 1] + gene_function(str_b[j]);
            }
            if (max < function[i - 1][j] + gene_function(str_a[i])) {
                max = function[i - 1][j] + gene_function(str_a[i]);
            }
            function[i][j] = max;
        }
    }
    
    return function[length_a][length_b];
}

int gene_function(char c)
{
    switch (c) {
    case 'A':
        return -3;
    case 'C':
        return -4;
    case 'G':
        return -2;
    case 'T':
        return -1;
    }
}

int gene_function(char a, char b)
{
    switch (a) {
    case 'A':
        switch (b) {
        case 'A':
            return 5;
        case 'C':
            return -1;
        case 'G':
            return -2;
        case 'T':
            return -1;
        }
    case 'C':
        switch (b) {
        case 'A':
            return -1;
        case 'C':
            return 5;
        case 'G':
            return -3;
        case 'T':
            return -2;
        }
    case 'G':
        switch (b) {
        case 'A':
            return -2;
        case 'C':
            return -3;
        case 'G':
            return 5;
        case 'T':
            return -2;
        }
    case 'T':
        switch (b) {
        case 'A':
            return -1;
        case 'C':
            return -2;
        case 'G':
            return -2;
        case 'T':
            return 5;
        }
    }
}
