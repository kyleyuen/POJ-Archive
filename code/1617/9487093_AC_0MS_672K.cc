#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve(const string& keyword);

struct Node {
	char word;
	unsigned index;
};

class Compare {
public:
    bool operator() (const Node& lhs, const Node& rhs) {
        return lhs.word < rhs.word;
    }
};

int main()
{
	string keyword;
	while (getline(cin, keyword)) {
		if (keyword == "THEEND") {
			break;
		}
		solve(keyword);
	}
	return 0;
}

void solve(const string& keyword)
{
	vector<Node> nodes(keyword.size());
	for (string::size_type i = 0; i != keyword.size(); ++i) {
		nodes[i].word = keyword[i];
		nodes[i].index = i;
	}

	sort(nodes.begin(), nodes.end(), Compare());
	string cipher;
	cin >> cipher;

	unsigned row = cipher.size() / keyword.size();
	unsigned column = keyword.size();
	vector< vector<char> > matrix(row, vector<char>(column));

	int index = 0;
	for (vector<Node>::size_type j = 0; j != nodes.size(); ++j) {
		for (unsigned i = 0; i != row; ++i) {
			matrix[i][nodes[j].index] = cipher[index];
			++index;
		}
	}

	for (unsigned i = 0; i != row; ++i) {
		for (unsigned j = 0; j != column; ++j) {
			cout << matrix[i][j];
		}
	}
	cout << endl;
	cin.get();
}
