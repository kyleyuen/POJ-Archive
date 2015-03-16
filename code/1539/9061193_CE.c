#include <iostream>
#include <string>
#include <cctype>

using namespace std;

struct Variable {
	char letter;
	int value;
	bool exist;
};

Variable variable[26];

int solve(string& expression);
void clear();
void print();

int main()
{
	string expression;
	while (getline(cin, expression)) {
		cout << "Expression: " << expression << endl;
		clear();
		cout << "    value = " << solve(expression) << endl;
		print();
	}
	return 0;
}

int solve(string& expression)
{
	for (string::size_type i = 0; i != expression.size(); ++i) {
		if (expression[i] == '+' && expression[i + 1] == '+' && islower(expression[i + 2])) {
		    expression[i] = expression[i + 1] = ' ';
			i += 2;
            variable[expression[i] - 'a'].letter = expression[i];
            variable[expression[i] - 'a'].value = expression[i] - 'a' + 2;
            variable[expression[i] - 'a'].exist = true;
            expression[i] = variable[expression[i] - 'a'].value;
		}
		else if (expression[i] == '-' && expression[i + 1] == '-' && islower(expression[i + 2])) {
			expression[i] = expression[i + 1] = ' ';
            i += 2;
            variable[expression[i] - 'a'].letter = expression[i];
            variable[expression[i] - 'a'].value = expression[i] - 'a';
            variable[expression[i] - 'a'].exist = true;
            expression[i] = variable[expression[i] - 'a'].value;
        }
    }
	for (string::size_type i = 0; i != expression.size(); ++i) {
		if (islower(expression[i]) && expression[i + 1] == '+' && expression[i + 2] == '+') {
		    expression[i + 1] = expression[i + 2] = ' ';
            variable[expression[i] - 'a'].letter = expression[i];
            variable[expression[i] - 'a'].value = expression[i] - 'a' + 2;
            variable[expression[i] - 'a'].exist = true;
            expression[i] = variable[expression[i] - 'a'].value - 1;
            i += 2;
		}
		else if (islower(expression[i]) && expression[i + 1] == '-' && expression[i + 2] == '-') {
			expression[i + 1] = expression[i + 2] = ' ';
            variable[expression[i] - 'a'].letter = expression[i];
            variable[expression[i] - 'a'].value = expression[i] - 'a';
            variable[expression[i] - 'a'].exist = true;
            expression[i] = variable[expression[i] - 'a'].value + 1;
            i += 2;
		}
	}
    for (string::size_type i = 0; i != expression.size(); ++i) {
        if (islower(expression[i])) {
            variable[expression[i] - 'a'].letter = expression[i];
            variable[expression[i] - 'a'].value = expression[i] - 'a' + 1;
            variable[expression[i] - 'a'].exist = true;
            expression[i] = variable[expression[i] - 'a'].value;
        }
    }

	int value = 0;
	unsigned index = 0;
	while (index != expression.size()) {
		if (0 <= expression[index] && expression[index] <= 30) {
			value = expression[index];
			break;
		}
		++index;
	}
	char op;
	for (string::size_type i = index + 1; i < expression.size(); ++i) {
		if (0 <= expression[i] && expression[i] <= 30) {
			if (op == '+') {
				value += expression[i];
			}
			else if (op == '-') {
				value -= expression[i];
			}
		}
		if (expression[i] == '+') {
            op = '+';
		}
		if (expression[i] == '-') {
            op = '-';
		}
	}
	return value;
}

void clear()
{
	for (char c = 'a'; c <= 'z'; ++c) {
		variable[c - 'a'].letter = c;
		variable[c - 'a'].value = c - 'a' + 1;
		variable[c - 'a'].exist = false;
	}
}

void print()
{
	for (int i = 0; i != 26; ++i) {
		if (variable[i].exist) {
			cout << "    " << variable[i].letter << " = " << variable[i].value << endl;
		}
	}
}
