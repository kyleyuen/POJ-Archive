#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int begin;
    int end;
};

class Compare {
public:
    bool operator() (const Interval& lhs, const Interval& rhs) { return lhs.begin < rhs.begin; }
};

void solve(int n);

int main()
{
    int n;
    cin >> n;
    solve(n);
    
    system("pause");
    return 0;
}

void solve(int n)
{
    vector<Interval> intervals(n);
    for (int i = 0; i != n; ++i) {
        cin >> intervals[i].begin >> intervals[i].end;
    }
    
    sort(intervals.begin(), intervals.end(), Compare());
    int begin = intervals[0].begin;
    int end = intervals[0].end;
    for (int i = 1; i != n; ++i) {
        if (intervals[i].begin <= end) {
            begin = (begin < intervals[i].begin) ? begin : intervals[i].begin;
            end = (end > intervals[i].end) ? end : intervals[i].end;
        }
        else {
            cout << begin << ' ' << end << endl;
            begin = intervals[i].begin;
            end = intervals[i].end;
        }
    }
    cout << begin << ' ' << end << endl;
}
