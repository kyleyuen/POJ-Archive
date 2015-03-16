#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Excuse {
	string str;
	int level;
};

class Compare {
public:
	bool operator() (const Excuse& lhs, const Excuse& rhs) {
		return lhs.level > rhs.level;
	}
};

void solve(int key_number, int excuse_number);
int getKeywords(const string& str, vector<string>& keywords);

int main()
{
	int key_number, excuse_number;
	int index = 1;
	while (cin >> key_number >> excuse_number) {
		cout << "Excuse Set #" << index << endl;
		solve(key_number, excuse_number);
		++index;
		cout << endl;
	}
	return 0;
}

void solve(int key_number, int excuse_number)
{
	vector<string> keywords;
	for (int i = 0; i != key_number; ++i) {
		string line;
		cin >> line;
		keywords.push_back(line);
	}

    cin.get();
	vector<Excuse> excuses;
	for (int i = 0; i != excuse_number; ++i) {
		Excuse excuse;
		getline(cin, excuse.str);
		excuse.level = getKeywords(excuse.str, keywords);
		excuses.push_back(excuse);
	}
	sort(excuses.begin(), excuses.end(), Compare());

	int result = excuses[0].level;
	for (vector<Excuse>::size_type i = 0; i != excuses.size(); ++i) {
		if (excuses[i].level < result) {
			break;
		}
		cout << excuses[i].str << endl;
	}
}

int getKeywords(const string& str, vector<string>& keywords)
{
	int result = 0;
	string temp(str);
	for (string::size_type i = 0; i != temp.size(); ++i) {
		if (isupper(temp[i])) {
			temp[i] = tolower(temp[i]);
		}
	}
	for (vector<string>::size_type i = 0; i != keywords.size(); ++i) {
		string::size_type position = temp.find(keywords[i]);
		if (position == string::npos) {
			continue;
		}

		if (position != 0 && isalpha(temp[position - 1])) {
			continue;
		}
		position += keywords[i].size();
		if (position == temp.size() || !isalpha(temp[position])) {
			++result;
		}
	}
	return result;
}
