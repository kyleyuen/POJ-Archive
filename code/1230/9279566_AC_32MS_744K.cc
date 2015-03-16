#include <iostream>
#include <list>

using namespace std;

struct Wall {
	int index;
	int start;
	int end;
};

int solve(int walls_number, int maximum);
void remove_wall(list<Wall>& walls, int coulumn);

int main()
{
	int total_cases;
	cin >> total_cases;
	for (int i = 1; i <= total_cases; ++i) {
		int walls_number, maximum;
		cin >> walls_number >> maximum;
		cout << solve(walls_number, maximum) << endl;
	}
	return 0;
}

int solve(int walls_number, int maximum)
{
	list<Wall> walls;
	int row = 0;
	int column = 0;
	for (int i = 0; i != walls_number; ++i) {
		Wall wall;
		cin >> wall.start >> wall.index >> wall.end >> wall.index;
		if (wall.start > wall.end) {
			int temp = wall.start;
			wall.start = wall.end;
			wall.end = temp;
		}

		if (row < wall.index) {
            row = wall.index;
		}
		if (column < wall.end) {
            column = wall.end;
		}
		walls.push_back(wall);
	}

	int result = 0;
 	for (int j = 0; j <= column; ++j) {
		int count = 0;
		for (list<Wall>::iterator iter = walls.begin(); iter != walls.end(); ++iter) {
			if (iter->start <= j && j <= iter->end) {
				++count;
			}
		}
		while (count > maximum) {
			remove_wall(walls, j);
			++result;
			--count;
		}
	}

	return result;
}

void remove_wall(list<Wall>& walls, int coulumn)
{
	list<Wall>::iterator index;
	int max = 0;
	for (list<Wall>::iterator iter = walls.begin(); iter != walls.end(); ++iter) {
		if (iter->start <= coulumn && coulumn <= iter->end && max < iter->end) {
			max = iter->end;
			index = iter;
		}
	}
	walls.erase(index);
}
