#include <iostream>
#include <vector>

using namespace std;

struct Cluster {
    int place;
    int target;
};

void solve();
void move(Cluster& cluster, vector<bool>& state);

int main()
{
    solve();
    return 0;
}

void solve()
{
    int space;
    int files;
    cin >> space >> files;

    vector<Cluster> clusters;
    vector<bool> state(space + 1);
    vector<int> original(space + 1);
    int index = 1;
    for (int i = 0; i != files; ++i) {
        int file_clusters;
        cin >> file_clusters;
        for (int j = 0; j != file_clusters; ++j) {
            Cluster temp;
            cin >> temp.place;
            temp.target = index;
            clusters.push_back(temp);
            state[temp.place] = true;
            original[temp.place] = index - 1;
            ++index;
        }
    }

    bool judge = true;
    for (int i = 0; i != clusters.size(); ++i) {
        if (!state[clusters[i].target]) {
            judge = false;
            move(clusters[i], state);
        }
    }
    for (int i = 0; i != clusters.size(); ++i) {
        if (!state[clusters[i].target]) {
            move(clusters[i], state);
        }
        else if (clusters[i].place != clusters[i].target) {
            judge = false;
            int location = space;
            while (location != 0) {
                if (!state[location]) {
                    break;
                }
                --location;
            }
            cout << clusters[i].target << ' ' << location << endl;
            state[clusters[i].target] = false;
            clusters[original[i + 1]].place = location;
            state[location] = true;
            move(clusters[i], state);
        }
    }

    if (judge) {
        cout << "No optimization needed" << endl;
    }
}

void move(Cluster& cluster, vector<bool>& state)
{
    cout << cluster.place << ' ' << cluster.target << endl;
    state[cluster.place] = false;
    cluster.place = cluster.target;
    state[cluster.place] = true;
}
