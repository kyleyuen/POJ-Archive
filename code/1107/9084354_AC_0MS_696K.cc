#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(string& message, int key, char lower_bound, char upper_bound);
void unique(string& message, int key);
void rotate(vector<int>& index, int k);
void assign(string& message, vector<char>& letter, vector<int>& index);

int main()
{
	int k1, k2, k3;
	while (cin >> k1 >> k2 >> k3) {
		if (k1 == 0 && k2 == 0 && k3 == 0) {
			break;
		}
		string message;
		cin >> message;
		solve(message, k1, 'a', 'i');
		solve(message, k2, 'j', 'r');
		unique(message, k3);
		cout << message << endl;
	}
	return 0;
}

void solve(string& message, int key, char lower_bound, char upper_bound)
{
	vector<int> index;
	vector<char> letter;
	for (string::size_type i = 0; i != message.size(); ++i) {
		if (lower_bound <= message[i] && message[i] <= upper_bound) {
			index.push_back(i);
			letter.push_back(message[i]);
		}
	}
	rotate(index, key);
	assign(message, letter, index);
}

void unique(string& message, int key)
{
	vector<int> index;
	vector<char> letter;
	for (string::size_type i = 0; i != message.size(); ++i) {
		if (('s' <= message[i] && message[i] <= 'z') || message[i] == '_') {
			index.push_back(i);
			letter.push_back(message[i]);
		}
	}
	rotate(index, key);
	assign(message, letter, index);
}

void rotate(vector<int>& index, int k)
{
    if (index.size() == 0) {
        return;
    }
    if (k >= index.size()) {
        k %= index.size();
    }
	for (int i = 0; i != k / 2; ++i) {
		int temp = index[i];
		index[i] = index[k - i - 1];
		index[k - i- 1] = temp;
	}
	for (int i = k; i != (index.size() + k) / 2; ++i) {
		int temp = index[i];
		index[i] = index[index.size() - i - 1 + k];
		index[index.size() - i - 1 + k] = temp;
	}
	for (int i = 0; i != index.size() / 2; ++i) {
		int temp = index[i];
		index[i] = index[index.size() - i - 1];
		index[index.size() - i - 1] = temp;
	}
}

void assign(string& message, vector<char>& letter, vector<int>& index)
{
	for (vector<int>::size_type i = 0; i != index.size(); ++i) {
		message[index[i]] = letter[i];
	}
}
