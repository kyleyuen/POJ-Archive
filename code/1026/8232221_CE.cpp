#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

void solve(int n);
void sort_by_precedence(vector<int>& precedence, vector< vector<int> >& order);

int main()
{
	int n;
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
	vector<int> precedence(n);
	for (int i = 0; i != precedence.size(); ++i) {
		cin >> precedence[i];
	}
	
	
	int k;
	while (cin >> k) {
		if (k == 0) {
			break;
		}
		char c;
		getchar();
		vector<char> message;
		while ((c = getchar()) != '\n') {
			message.push_back(c);
		}
		while (message.size() < n) {
			message.push_back(' ');
		}
		
		vector <vector<int> > order(n);
		sort_by_precedence(precedence, order);

		vector<char> temp(message);
		for (vector<char>::size_type i = 0; i != message.size(); ++i) {
			temp[ order[i][k % order[i].size()] ] = message[i];
		}
		for (vector<char>::size_type i = 0; i != temp.size(); ++i) {
			cout << temp[i];
		}
		cout << endl;
	}
}

void sort_by_precedence(vector<int>& precedence, vector< vector<int> >& order)
{
	for (vector<int>::size_type i = 0; i != order.size(); ++i) {
		order[i].push_back(i);
		int j = precedence[i] - 1;
		while (find(order[i].begin(), order[i].end(), j) == order[i].end()) {
			order[i].push_back(j);
			j = precedence[j] - 1;
		}
	}
}