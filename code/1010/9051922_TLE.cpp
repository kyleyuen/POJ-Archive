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

void solve(vector<int>& stamps, vector<int>& customers);
void search(vector<int>& stamps, int needs, int value, Stamp& data);
bool increase_type(Stamp& data, int in);
void compare(Stamp& data);
void print_result(vector<int>& stamps, int needs);

int main()
{
    vector<int> stamps;
    vector<int> customers;
    bool chance = true;
    int input;

    while (cin >> input) {
        if (input == 0) {
            chance = !chance;
            if (chance) {
                solve(stamps, customers);
                stamps.clear();
                customers.clear();
            }
            continue;
        }
        if (chance) {
            stamps.push_back(input);
        }
        else {
            customers.push_back(input);
        }
    }

    return 0;
}

void solve(vector<int>& stamps, vector<int>& customers)
{
	sort(stamps.begin(), stamps.end());
    for (vector<int>::size_type i = 0; i != customers.size(); ++i) {
		best.type = best.number = best.maximum = 0;
		best_index[0] = best_index[1] = best_index[2] = best_index[3] = NIL;
		index[0] = index[1] = index[2] = index[3] = NIL;
        tie = false;

		Stamp data;
		data.type = data.number = data.maximum = 0;
        search(stamps, customers[i], 0, data);
        print_result(stamps, customers[i]);
    }
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
			best_index[0] = index[0];
			best_index[1] = index[1];
			best_index[2] = index[2];
			best_index[3] = index[3];
            tie = false;
    }
    else if (data.type == best.type && data.number == best.number && data.maximum == best.maximum) {
        int temp[4];
        temp[0] = index[0];
        temp[1] = index[1];
        temp[2] = index[2];
        temp[3] = index[3];
        sort(temp, temp + 4);
        for (int i = 0; i != 4; ++i) {
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
