#include <iostream>
#include <string>
#include <map>
#include <set>
#include <list>

using namespace std;

struct Directory {
	string name;
	set<string> file;
	list<Directory> dir;
};

void get_file(Directory& root, string& line);
void get_directory(Directory& root, string& name);
void print(Directory& root, int depth);

int main()
{
	int counter = 1;
	string line;
	while (getline(cin, line)) {
		if (line == "#") {
			break;
		}

		Directory root;
		root.name = "ROOT";
		do {
			if (line[0] == 'f') {
				get_file(root, line);
			}
			else if (line[0] == 'd') {
				get_directory(root, line);
			}
			else {
				break;
			}
		} while (getline(cin, line));
		cout << "DATA SET " << counter << ":" << endl;
		print(root, 0);
		cout << endl;
		++counter;
	}
	return 0;
}

void get_file(Directory& root, string& line)
{
	root.file.insert(line);
}

void get_directory(Directory& root, string& name)
{
	Directory directory;
	directory.name = name;

	string line;
	while (getline(cin, line)) {
		if (line == "]") {
			root.dir.push_back(directory);
			break;
		}

		switch (line[0]) {
		case 'f':
			directory.file.insert(line);
			break;
		case 'd':
			get_directory(directory, line);
			break;
		}
	}
}

void print(Directory& root, int depth)
{
	cout << root.name << endl;
	for (list<Directory>::iterator iter = root.dir.begin(); iter != root.dir.end(); ++iter) {
		for (int i = 0; i <= depth; ++i) {
			cout << "|     ";
		}
		print(*iter, depth + 1);
	}
	for (set<string>::iterator iter = root.file.begin(); iter != root.file.end(); ++iter) {
	    for (int i = 0; i != depth; ++i) {
			cout << "|     ";
		}
		cout << *iter << endl;
	}
}
