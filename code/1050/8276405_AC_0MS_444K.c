#include <stdio.h>

int max_sum(int a[][101], int n, int m);
int bc(int record[][101], int a, int c, int i);

int main(void)
{
    int width;
    int i, j;
    int a[101][101];
    
    scanf("%d", &width);
    for (i = 1; i <= width; ++i) {
        for (j = 1; j <= width; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%d\n", max_sum(a, width, width));
    return 0;
}

int max_sum(int array[][101], int n, int m)
{
    int a, c;
    int i, j;
    int record[101][101];
    int maximum = -1000;
    
    for (i = 0; i <= n; ++i) {
        record[i][0] = 0;
    }
    for (j = 0; j <= m; ++j) {
        record[0][j] = 0;
    }
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= m; ++j) {
            record[i][j] = record[i - 1][j] + record[i][j - 1] - record[i - 1][j - 1] + array[i][j];
        }
    }
    
    for (a = 1; a <= n; ++a) {
        for (c = a; c <= n; ++c) {
            int start = bc(record, a, c, m);
            int all = bc(record, a, c, m);
            for (i = m - 1; i >= 1; --i) {
                if (start < 0) {
                    start = 0;
                }
                start += bc(record, a, c, i);
                if (start > all) {
                    all = start;
                }
            }
            if (all > maximum) {
                maximum = all;
            }
        }
    }
    return maximum;
}

int bc(int record[][101], int a, int c, int i)
{
    return record[c][i] - record[a - 1][i] - record[c][i - 1] + record[a - 1][i - 1];
}
