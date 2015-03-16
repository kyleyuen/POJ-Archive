#include <iostream>
#include <string>

using namespace std;

void solve(const string& line);
bool check(const string& line);

int main()
{
	string line;
	while (cin >> line) {
		if (line == "end") {
			break;
		}
		solve(line);
	}
	return 0;
}

void solve(const string& line)
{
	cout << "<" << line << ">";
	if (check(line)) {
		cout << " is acceptable." << endl;
	}
	else {
		cout << " is not acceptable." << endl;
	}
}

bool check(const string& line)
{
	bool exist = false;

	char previous = 0;
	int vowels = 0;
	int consonants = 0;
	for (string::size_type i = 0; i != line.size(); ++i) {
		if (line[i] == 'a' || line[i] == 'e' || line[i] == 'i' || line[i] == 'o' || line[i] == 'u') {
			exist = true;
			++vowels;
			consonants = 0;
		}
		else {
			++consonants;
			vowels = 0;
		}

		if (vowels == 3 || consonants == 3) {
			return false;
		}
		if (line[i] == previous && (line[i] != 'e' && line[i] != 'o')) {
			return false;
		}
		previous = line[i];
	}
	return exist;
}
