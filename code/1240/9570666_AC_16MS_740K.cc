#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(int nodes);
void countSons(int curPrePos, int curPostPos, int endPrePos, const string& pre, const string& post, vector<int>& counter);
int fun(int n, int m);

int main()
{
	int nodes;
	while (cin >> nodes) {
		if (nodes == 0) {
			break;
		}
		solve(nodes);
	}
	return 0;
}

void solve(int nodes)
{
	string pre_order;
	string post_order;
    cin >> pre_order >> post_order;

	vector<int> counter(pre_order.size());
	countSons(0, 0, pre_order.size() - 1, pre_order, post_order, counter);

	long long result = 1;
	for (vector<int>::size_type i = 0; i != counter.size(); ++i) {
		result *= fun(nodes, counter[i]);
	}
	cout << result << endl;
}

void countSons(int curPrePos, int curPostPos, int endPrePos, const string& pre, const string& post, vector<int>& counter)
{
    if(curPrePos == endPrePos)
        return;
    int pPre = curPrePos + 1, postP;
    char c;
    while(pPre <= endPrePos)
    {
        c = pre[pPre];
        counter[curPrePos]++;
        postP = curPostPos;
        while(post[postP] != c) postP++;
        countSons(pPre, curPostPos, pPre + (postP - curPostPos), pre, post, counter);
        pPre = pPre + (postP - curPostPos) + 1;
        curPostPos = postP + 1;
    }
}

int fun(int n, int m)
{
	if (m == 0 || m == n) {
		return 1;
	}
	return fun(n - 1, m) + fun(n - 1, m - 1);
}
