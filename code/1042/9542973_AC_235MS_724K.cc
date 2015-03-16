#include <iostream>
#include <vector>

using namespace std;

void solve(int lakes);
void calculate(int time, int lakes, vector<int>& fish, vector<int>& decrease, vector<int>& distance);
void print(vector<int>& result, int total_fishs);

int main()
{
	int lakes;
	while (cin >> lakes) {
		if (lakes == 0) {
			break;
		}
		solve(lakes);
	}
	return 0;
}

void solve(int lakes)
{
	int time;
	cin >> time;
	time *= 12;

	vector<int> fish(lakes);
	for (int i = 0; i < lakes; ++i) {
		cin >> fish[i];
	}
	vector<int> decrease(lakes);
	for (int i = 0; i < lakes; ++i) {
		cin >> decrease[i];
	}
	vector<int> distance(lakes - 1);
	for (int i = 0; i < lakes - 1; ++i) {
		cin >> distance[i];
	}

	calculate(time, lakes, fish, decrease, distance);
}

void calculate(int time, int lakes, vector<int>& fish, vector<int>& decrease, vector<int>& distance)
{
	vector<int> result;
	int total_fishs = -1;
	for (int i = 0; i < lakes; ++i) {
		int current_time = time;
		for (int j = 0; j < i; ++j) {
			current_time -= distance[j];
		}
		if (current_time < 0) {
			break;
		}

		vector<int> current_fish;
		for (int j = 0; j <= i; ++j) {
            current_fish.push_back(fish[j]);
		}

		int catch_fishs = 0;
		vector<int> time_spend(lakes);
		while (current_time > 0) {
			int max_index = 0;
			for (int j = 1; j <= i; ++j) {
				if (current_fish[j] > current_fish[max_index]) {
					max_index = j;
				}
			}
			catch_fishs += current_fish[max_index];
			++time_spend[max_index];
			current_fish[max_index] -= decrease[max_index];
			if (current_fish[max_index] < 0) {
				current_fish[max_index] = 0;
			}
			--current_time;
		}

		if (total_fishs < catch_fishs) {
			total_fishs = catch_fishs;
			result = time_spend;
		}
	}
	print(result, total_fishs);
}

void print(vector<int>& result, int total_fishs)
{
    cout << result[0] * 5;
	for (vector<int>::size_type i = 1; i != result.size(); ++i) {
		cout << ", " << result[i] * 5;
	}
	cout << endl;
	cout << "Number of fish expected: " << total_fishs << endl;
	cout << endl;
}
