#include <iostream>
#include <vector>

using namespace std;

void solve();

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

    vector<int> clusters(space + 1);
    vector<int> target(space + 1);
    int index = 1;
    for (int i = 0; i != files; ++i) {
        int file_clusters;
        cin >> file_clusters;
        for (int j = 0; j != file_clusters; ++j) {
            cin >> target[index];
            clusters[target[index]] = index;
            ++index;
        }
    }

    bool flag = true;
    for (int i = 1; i != index; ++i) {
        if (clusters[i] == 0) {
            flag = false;
            cout << target[i] << ' ' << i << endl;
            clusters[i] = clusters[target[i]];
            clusters[target[i]] = 0;
        }
    }
    for (int i = 1; i != index; ++i) {
        if (clusters[i] == 0) {
            for (int j = space; j != 0; --j) {
                if (clusters[j] == i) {
                    cout << j << ' ' << i << endl;
                    clusters[i] = i;
                    clusters[j] = 0;
                    break;
                }
            }
        }
        else if (clusters[i] != i) {
            flag = false;
            for (int j = space; j != 0; --j) {
                if (clusters[j] == 0) {
                    cout << i << ' ' << j << endl;
                    cout << target[i] << ' ' << i << endl;
                    clusters[j] = clusters[i];
                    clusters[i] = clusters[target[i]];
                    clusters[target[i]] = 0;
                    break;
                }
            }
        }
    }
    for (int i = space; i != 0; --i) {
        if (clusters[i] == 0) {
            break;
        }
        cout << i << ' ' << clusters[i] << endl;
        clusters[clusters[i]] = target[clusters[clusters[i]]];
        clusters[i] = 0;
    }
    if (flag) {
        cout << "No optimization needed" << endl;
    }
}
