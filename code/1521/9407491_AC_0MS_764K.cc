#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node {
	Node(int v): value(v), left(0), right(0) { }
	int value;
	Node* left;
	Node* right;
};

class Compare {
public:
	bool operator() (const Node* lhs, const Node* rhs) {
		return lhs->value > rhs->value;
	}
};

void solve(const string& line);
int huffman(int key[27]);
void traversal(Node* ptr, int depth, int& result);

int main()
{
	string line;
	while (cin >> line) {
		if (line == "END") {
			break;
		}
		solve(line);
	}
	return 0;
}

void solve(const string& line)
{
	int key[27] = { 0 };
	for (string::size_type i = 0; i != line.size(); ++i) {
		if (line[i] == '_') {
			++key[26];
		}
		else {
			++key[line[i] - 'A'];
		}
	}

	int result = huffman(key);
	int length = line.size() * 8;
	cout << length << ' ' << result << ' ' << fixed << setprecision(1) << double(length) / result << endl;
}

int huffman(int key[27])
{
	priority_queue<Node*, vector<Node*>, Compare> queue;
	int counter = 0;
	for (int i = 0; i != 27; ++i) {
		if (key[i] > 0) {
		    queue.push(new Node(key[i]));
		    ++counter;
		}
	}

	if (counter == 1) {
		return queue.top()->value;
	}
	while (queue.size() != 1) {
		Node* ptr = new Node(0);
		ptr->left = queue.top();
		queue.pop();
		ptr->right = queue.top();
		queue.pop();
		ptr->value = ptr->left->value + ptr->right->value;
		queue.push(ptr);
	}

	int result = 0;
	Node* root = queue.top();
	traversal(root, 0, result);
	return result;
}

void traversal(Node* ptr, int depth, int& result)
{
	if (ptr->left == 0 && ptr->right == 0) {
		result += depth * ptr->value;
		return;
	}

	if (ptr->left != 0) {
		traversal(ptr->left, depth + 1, result);
	}
	if (ptr->right != 0) {
		traversal(ptr->right, depth + 1, result);
	}
}
