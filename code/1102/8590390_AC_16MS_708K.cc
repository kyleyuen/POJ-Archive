#include <iostream>
#include <vector>

using namespace std;

void solve(int size, int number);
void convert_to_digit(int number, vector<int>& digit);
void print_char(char c, int n);

int main()
{
    int size;
    int number;
    
    while (cin >> size >> number) {
        if (size == 0 && number == 0) {
            break;
        }
        solve(size, number);
    }
    
    return 0;
}

void solve(int size, int number)
{
    vector<int> digit;
    convert_to_digit(number, digit);
    
    int i = 1;
    for (vector<int>::size_type j = 0; j != digit.size(); ++j) {
        cout << ' ';
        switch (digit[j]) {
            case 1:
            case 4:
                print_char(' ', size);
                break;
                        
            case 2:
            case 3:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 0:
                print_char('-', size);
                break;
            default:
                break;
        }
        cout << ' ';
        if (j != digit.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;
    ++i;
    
    while (i <= size + 1) {
        for (vector<int>::size_type j = 0; j != digit.size(); ++j) {
            switch (digit[j]) {
                case 1:
                case 2:
                case 3:
                case 7:
                    cout << ' ';
                    print_char(' ', size);
                    cout << '|';
                    break;
                        
                case 5:
                case 6:
                    cout << '|';
                    print_char(' ', size);
                    cout << ' ';
                    break;
                    
                case 4:
                case 8:
                case 9:
                case 0:
                    cout << '|';
                    print_char(' ', size);
                    cout << '|';
                    break;
                default:
                    break;
            }
            if (j != digit.size() - 1) {
                cout << ' ';
            }
        }
        cout << endl;
        ++i;
    }
    
    for (vector<int>::size_type j = 0; j != digit.size(); ++j) {
        cout << ' ';
        switch (digit[j]) {
            case 1:
            case 7:
            case 0:
                print_char(' ', size);
                break;
                        
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:            
            case 8:
            case 9:
                print_char('-', size);
                break;
            default:
                break;
        }
        cout << ' ';
        if (j != digit.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;
    ++i;
    
    while (i <= 2 * (size + 1)) {
        for (vector<int>::size_type j = 0; j != digit.size(); ++j) {
            switch (digit[j]) {
                case 1:
                case 3:
                case 4:
                case 5:
                case 7:
                case 9:
                    cout << ' ';
                    print_char(' ', size);
                    cout << '|';
                    break;
                        
                case 2:
                    cout << '|';
                    print_char(' ', size);
                    cout << ' ';
                    break;
                        
                case 6:
                case 8:
                case 0:
                    cout << '|';
                    print_char(' ', size);
                    cout << '|';
                    break;
                default:
                    break;
            }
            if (j != digit.size() - 1) {
                cout << ' ';
            }
        }
        cout << endl;
        ++i;
    }
    
    for (vector<int>::size_type j = 0; j != digit.size(); ++j) {
        cout << ' ';
        switch (digit[j]) {
            case 1:
            case 4:
            case 7:
                print_char(' ', size);
                break;
                        
            case 2:
            case 3:            
            case 5:
            case 6:
            case 8:
            case 9:
            case 0:
                print_char('-', size);
                break;
            default:
                break;
        }
        cout << ' ';
        if (j != digit.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl << endl;
}

void convert_to_digit(int number, vector<int>& digit)
{
    if (number == 0) {
        digit.push_back(0);
        return;
    }
    while (number != 0) {
        digit.push_back(number % 10);
        number /= 10;
    }
    for (vector<int>::size_type i = 0; i != digit.size() / 2; ++i) {
        int temp = digit[i];
        digit[i] = digit[digit.size() - i - 1];
        digit[digit.size() - i - 1] = temp;
    }
}

void print_char(char c, int n)
{
    for (int i = 0; i != n; ++i) {
        cout << c;
    }
}
