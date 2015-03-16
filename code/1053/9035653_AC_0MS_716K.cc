#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(vector<string>& deck);
bool judge(char a, char b, char c);

int main()
{
	vector<string> deck;
	string card;
	while (cin >> card) {
		deck.push_back(card);
		for (int i = 1; i != 12; ++i) {
			cin  >> card;
			deck.push_back(card);
		}
		solve(deck);
		deck.clear();
	}
	return 0;
}

void solve(vector<string>& deck)
{
	cout << "CARDS: ";
	for (vector<string>::size_type i = 0; i != deck.size(); ++i) {
		cout << ' ' << deck[i];
	}
	cout << endl;
	int counter = 0;
	cout << "SETS:   ";
	for (vector<string>::size_type i = 0; i != deck.size(); ++i) {
		for (vector<string>::size_type j = i + 1; j != deck.size(); ++j) {
			for (vector<string>::size_type k = j + 1; k != deck.size(); ++k) {
				if (!judge(deck[i][0], deck[j][0], deck[k][0])
					|| !judge(deck[i][1], deck[j][1], deck[k][1])
					|| !judge(deck[i][2], deck[j][2], deck[k][2])
					|| !judge(deck[i][3], deck[j][3], deck[k][3])) {
					continue;
				}
				++counter;
				if (counter == 1) {
					cout << "1.  ";
				}
				else {
					cout << "        " << counter << ".  ";
				}
				cout << deck[i] << ' ' << deck[j] << ' ' << deck[k] << endl;
			}
		}
	}
	if (counter == 0) {
		cout << "*** None Found ***" << endl;
	}
	cout << endl;
}

bool judge(char a, char b, char c)
{
	return (a == b && b == c) || (a != b && b != c && c != a);
}
