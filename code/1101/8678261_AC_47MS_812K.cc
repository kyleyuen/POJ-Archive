#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <deque>

using namespace std;

void solve(int width, int height);
int measure_path(vector< vector<int> >& token, int x, int y);

enum Dirction {
    NONE, UP, RIGHT, DOWN, LEFT
};

int main()
{
    int width;
    int height;

    for (int i = 1; cin >> width >> height; ++i) {
        if (width == 0 && height == 0) {
            break;
        }
        cout << "Board #" << i << ":" << endl;
        solve(width, height);
        cout << endl;
    }

    return 0;
}

void solve(int width, int height)
{
    cin.get();
    vector< vector<int> > board(height + 2, vector<int>(width + 2, 0));

    for (int i = 1; i <= height; ++i) {
        string line;
        getline(cin, line);
        for (int j = 1; j <= width; ++j) {
            if (line[j - 1] == 'X') {
                board[i][j] = 1;
            }
        }
    }

    int start[2];
    int end[2];
    for (int i = 1; ; ++i) {
        cin >> start[1] >> start[0] >> end[1] >> end[0];
        if (start[0] == 0 && start[1] == 0 && end[0] == 0 && end[1] == 0) {
            break;
        }

        vector< vector<int> > mark(height + 2, vector<int>(width + 2, 0));
        vector< vector<int> > token(height + 2, vector<int>(width + 2, NONE));
        deque< pair<int, int> > queue;

        queue.push_back(make_pair(start[0], start[1]));
        mark[start[0]][start[1]] == 1;
        board[end[0]][end[1]] = 0;
        while (!queue.empty()) {
            pair<int, int> vertex = queue.front();
            queue.pop_front();
            if (vertex.first == end[0] && vertex.second == end[1]) {
                break;
            }

            if (vertex.second != width + 1 && board[vertex.first][vertex.second + 1] == 0 && mark[vertex.first][vertex.second + 1] == 0) {
                queue.push_back(make_pair(vertex.first, vertex.second + 1));
                mark[vertex.first][vertex.second + 1] = 1;
                token[vertex.first][vertex.second + 1] = LEFT;
            }
            if (vertex.first != height + 1 && board[vertex.first + 1][vertex.second] == 0 && mark[vertex.first + 1][vertex.second] == 0) {
                queue.push_back(make_pair(vertex.first + 1, vertex.second));
                mark[vertex.first + 1][vertex.second] = 1;
                token[vertex.first + 1][vertex.second] = UP;
            }
            if (vertex.second != 0 && board[vertex.first][vertex.second - 1] == 0 && mark[vertex.first][vertex.second - 1] == 0) {
                queue.push_back(make_pair(vertex.first, vertex.second - 1));
                mark[vertex.first][vertex.second - 1] = 1;
                token[vertex.first][vertex.second - 1] = RIGHT;
            }
            if (vertex.first != 0 && board[vertex.first - 1][vertex.second] == 0 && mark[vertex.first - 1][vertex.second] == 0) {
                queue.push_back(make_pair(vertex.first - 1, vertex.second));
                mark[vertex.first - 1][vertex.second] = 1;
                token[vertex.first - 1][vertex.second] = DOWN;
            }

            mark[vertex.first][vertex.second] = 2;
        }
        board[end[0]][end[1]] = 1;

        cout << "Pair " << i << ": ";
        int result = measure_path(token, end[0], end[1]);
        if (result == 0) {
            cout << "impossible." << endl;
        }
        else {
            cout << result << " segments." << endl;
        }
    }
}

int measure_path(vector< vector<int> >& token, int x, int y)
{
    int segments = 0;
    int c = NONE;
    while (token[x][y] != NONE) {
        if (c != token[x][y]) {
            c = token[x][y];
            ++segments;
        }

        switch (token[x][y]) {
        case UP:
            --x;
            break;
        case RIGHT:
            ++y;
            break;
        case DOWN:
            ++x;
            break;
        case LEFT:
            --y;
            break;
        default:
            break;
        }
    }
    return segments;
}
