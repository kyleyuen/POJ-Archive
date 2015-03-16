#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

void web_navigation();

int main()
{
    web_navigation();
    return 0;
}

void web_navigation()
{
    stack<string> back_stack;
    stack<string> forward_stack;
    
    string command;
    string current_page("http://www.acm.org/");
    while (cin >> command) {
        if (command == "QUIT") {
            break;
        }
        
        if (command == "VISIT") {
            back_stack.push(current_page);
            while (!forward_stack.empty()) {
                forward_stack.pop();
            }
            cin >> current_page;
        }
        else if (command == "BACK") {
            if (back_stack.empty()) {
                cout << "Ignored" << endl;
                continue;
            }
            else {
                forward_stack.push(current_page);
                current_page = back_stack.top();
                back_stack.pop();
            }
        }
        else if (command == "FORWARD") {
            if (forward_stack.empty()) {
                cout << "Ignored" << endl;
                continue;
            }
            else {
                back_stack.push(current_page);
                current_page = forward_stack.top();
                forward_stack.pop();
            }
        }
        cout << current_page << endl;
    }
}