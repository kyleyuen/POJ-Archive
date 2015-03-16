#include <iostream>
#include <string>

using namespace std;

struct Team {
    Team(): name(), solved(0), point(0) { }
	string name;
	int solved;
	int point;
};

void solve(int teams);

int main()
{
	int teams;
	cin >> teams;
	solve(teams);
	return 0;
}

void solve(int teams)
{
	Team result;
	for (int i = 0; i != teams; ++i) {
		Team temp;
		cin >> temp.name;
		for (int j = 0; j != 4; ++j) {
			int submition, time;
			cin >> submition >> time;
			if (time != 0) {
				++temp.solved;
				temp.point += time + (submition - 1) * 20;
			}
		}
		if (result.solved < temp.solved || (result.solved == temp.solved && result.point > temp.point)) {
			result = temp;
		}
	}
	cout << result.name << ' ' << result.solved << ' ' << result.point << endl;
}
