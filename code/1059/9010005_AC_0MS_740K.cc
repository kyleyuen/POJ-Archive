#include <iostream>
#include <vector>

using namespace std;

struct Connect {
	int start;
	int end;
};

int solve(int players_number);

vector<int> die_throw;

int main()
{
	int temp;
	while (cin >> temp) {
        if (temp == 0) {
            break;
        }
        die_throw.push_back(temp);
	}

    int players_number;
	while (cin >> players_number) {
        if (players_number == 0) {
            break;
        }
        cout << solve(players_number) << endl;
    }

	return 0;
}

int solve(int players_number)
{
	vector<Connect> connects;
	Connect temp;
	while (cin >> temp.start >> temp.end) {
		if (temp.start == 0 && temp.end == 0) {
			break;
		}
		connects.push_back(temp);
	}

	vector<int> opportunity;
	while (true) {
		int t;
		cin >> t;
		if (t == 0) {
			break;
		}
		opportunity.push_back(t);
	}

	int turn = 0;
	int winer;
	vector<int> players(players_number);
	vector<bool> state(players_number, true);
	for (vector<int>::size_type i = 0; i != die_throw.size(); ++i) {
		if (!state[turn]) {
			state[turn] = true;
			--i;
			turn = (turn + 1) % players_number;
			continue;
		}

		if (players[turn] + die_throw[i] == 100) {
			winer = turn + 1;
			break;
		}
		else if (players[turn] + die_throw[i] < 100) {
			players[turn] += die_throw[i];
		}

		for (vector<Connect>::size_type j = 0; j != connects.size(); ++j) {
			if (connects[j].start == players[turn]) {
				players[turn] = connects[j].end;
				break;
			}
		}

		for (vector<int>::size_type j = 0; j != opportunity.size(); ++j) {
			if (opportunity[j] > 0 && players[turn] == opportunity[j]) {
				turn = (turn + players_number - 1) % players_number;
				break;
			}
			else if (opportunity[j] < 0 && players[turn] == -opportunity[j]) {
				state[turn] = false;
				break;
			}
		}
		turn = (turn + 1) % players_number;
	}
	return winer;
}
