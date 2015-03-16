#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stamp {
	int type;
	int number;
	int maximum;
};

int NIL = 100;
bool tie;
Stamp best;
int best_index[4];
int index[4];

void solve(vector<int>& stamps, int needs);
void search(vector<int>& stamps, int needs, int value, Stamp& data);
bool increase_type(Stamp& data, int in);
void compare(Stamp& data);
void print_result(vector<int>& stamps, int needs);

int main()
{
    int temp;

    loop:
    while (cin >> temp) {
        vector<int> stamps;
        stamps.push_back(temp);
        while (cin >> temp) {
            if (temp == 0) {
                break;
            }
            stamps.push_back(temp);
        }
        sort(stamps.begin(), stamps.end());

        while (cin >> temp) {
            if (temp == 0) {
                break;
            }
            solve(stamps, temp);
        }
        goto loop;
    }

    return 0;
}

void solve(vector<int>& stamps, int needs)
{
    best.type = best.number = best.maximum = 0;
    best_index[0] = best_index[1] = best_index[2] = best_index[3] = NIL;
    index[0] = index[1] = index[2] = index[3] = NIL;
    tie = false;

    Stamp data;
    data.type = data.number = data.maximum = 0;
    search(stamps, needs, 0, data);
    print_result(stamps, needs);
}

void search(vector<int>& stamps, int needs, int value, Stamp& data)
{
    if (data.number > 4) {
        return;
    }
    if (value == needs) {
        compare(data);
		return;
    }

    for (vector<int>::size_type i = 0; i != stamps.size(); ++i) {
        if (stamps[i] + value > needs) {
            break;
        }

		bool result = increase_type(data, i);
        index[data.number] = i;
		++data.number;
		int max = data.maximum;
		if(data.maximum < stamps[i]) {
			data.maximum = stamps[i];
		}
		search(stamps, needs, stamps[i] + value, data);

		if (result) {
			--data.type;
		}
		--data.number;
		index[data.number] = NIL;
		data.maximum = max;
    }
}

bool increase_type(Stamp& data, int in)
{
	for (int i = 0; i != 4; ++i) {
		if (index[i] == in) {
			return false;
		}
	}
	++data.type;
	return true;
}

void compare(Stamp& data)
{
    if ((data.type > best.type)
		|| (data.type == best.type && data.number < best.number)
        || (data.type == best.type && data.number == best.number && data.maximum > best.maximum)) {
            best = data;
			for (int i = 0; i != 4; ++i) {
                best_index[i] = index[i];
            }
            tie = false;
    }
    else if (data.type == best.type && data.number == best.number && data.maximum == best.maximum) {
        int temp[4];
        for (int i = 0; i != 4; ++i) {
            temp[i] = index[i];
        }
        for (int i = 0; i != 3; ++i) {
            for (int j = 3; j != i; --j) {
                if (temp[j] < temp[j - 1]) {
                    int t = temp[j - 1];
                    temp[j - 1] = temp[j];
                    temp[j] = t;
                }
            }
            if (best_index[i] != temp[i]) {
                tie = true;
                break;
            }
        }
    }
}

void print_result(vector<int>& stamps, int needs)
{
    cout << needs << ' ';
    if (best.type == 0) {
        cout << "---- none" << endl;
    }
    else {
        cout << '(' << best.type << "):";
        if (tie) {
            cout << " tie" << endl;
        }
        else {
			for (int i = 0; i != 4; ++i) {
				if (best_index[i] == NIL) {
					break;
				}
				cout << ' ' << stamps[best_index[i]];
			}
			cout << endl;
        }
    }
}
