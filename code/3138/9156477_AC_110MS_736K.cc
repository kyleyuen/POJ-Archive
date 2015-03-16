#include <iostream>
#include <vector>

using namespace std;

int solve(int school, int team, int problem);

int main()
{
	for (int i = 1; ; ++i) {
		int school, team, problem;
		cin >> school >> team >> problem;
		if (team == 0 && problem == 0) {
			break;
		}

		cout << "Case " << i << ": ";
		cout << solve(school, team, problem) << endl;
	}
	return 0;
}

int solve(int school, int team, int problem)
{
	int result = 0;
	vector<bool> judge(school + 1, true);
	for (int i = 0; i != school; ++i) {
		int id, c1, c2;
		cin >> id >> c1 >> c2;
		result += c1 + c2;
	}
	for (int i = 0; i != team; ++i) {
		int id, solved;
		cin >> id >> solved;
		if (judge[id] && solved >= problem) {
			judge[id] = false;
			++result;
		}
	}
	return result;
}
