#include <iostream>
#include <list>
#include <string>

using namespace std;

template <typename T>
struct TreeNode {
    TreeNode(const T& key): val(key), left(0), right(0) { }
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

template <typename T>
class BinarySearchTree {
public:
    BinarySearchTree(): root(0), size_imp(0) { }
    ~BinarySearchTree() {
		destroy(root);
	}

    const unsigned size() const { return size_imp; }

    bool insert(const T& val) {
		return doInsert(val, root);
	}
    void preorderTreeWalk() {
		doPreorderTreeWalk(root);
	}
private:
    bool doInsert(const T& val, TreeNode<T>*& ptr) {
		if (ptr == 0) {
			ptr = new TreeNode<T>(val);
			++size_imp;
			return true;
		}

		if (val < ptr->val) {
			return doInsert(val, ptr->left);
		}
		else if (val > ptr->val) {
			return doInsert(val, ptr->right);
		}
		else {
			return false;
		}
	}
    void doPreorderTreeWalk(TreeNode<T>* ptr) {
		if (ptr != 0) {
			cout << ptr->val;
			doPreorderTreeWalk(ptr->left);
			doPreorderTreeWalk(ptr->right);
		}
	}
    void destroy(TreeNode<T>* ptr) {
		if (ptr != 0) {
			destroy(ptr->left);
			destroy(ptr->right);
			delete ptr;
		}
	}

    TreeNode<T>* root;
    unsigned size_imp;
};


void solve(string& line);

int main()
{
	string line;
	while (getline(cin, line)) {
		solve(line);
	}
	return 0;
}

void solve(string& line)
{
	list<string> nodes;
	nodes.push_front(line);
	while (getline(cin, line)) {
		if (line == "*" || line == "$") {
			break;
		}
		nodes.push_front(line);
	}

	BinarySearchTree<char> tree;
	for (list<string>::iterator iter = nodes.begin(); iter != nodes.end(); ++iter) {
		for (string::size_type i = 0; i != iter->size(); ++i) {
			tree.insert((*iter)[i]);
		}
	}
	tree.preorderTreeWalk();
	cout << endl;
}
