#include <iostream>
#include <vector>
#include <stack>

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
    int counter = 1;
    for (int i = 0; i != files; ++i) {
        int file_clusters;
        cin >> file_clusters;
        for (int j = 0; j != file_clusters; ++j) {
            int temp;
            cin >> temp;
            clusters[temp] = counter;
            ++counter;
        }
    }
    
    bool judge = true;
    stack<int> stk;
    for (int i = 1; i <= space; ++i) {
        if (clusters[i] == 0 || clusters[i] == i) {
            continue;
        }
        
        judge = false;
        stk.push(i);
        int index = clusters[i];
        while (clusters[index] != 0 && index != i) {
            stk.push(index);
            index = clusters[index];
        }
        if (clusters[index] == 0) {
            while (!stk.empty()) {
                int temp = stk.top();
                stk.pop();
                clusters[clusters[temp]] = clusters[temp];
                cout << temp << ' ' << clusters[temp] << endl;
            }
            clusters[i] = 0;
        }
        else if (index == i) {
            int location = space;
            while (location != 0) {
                if (clusters[location] == 0) {
                    break;
                }
                --location;
            }
            cout << stk.top() << ' ' << location << endl;
            stk.pop();
            while (!stk.empty()) {
                int temp = stk.top();
                stk.pop();
                clusters[clusters[temp]] = clusters[temp];
                cout << temp << ' ' << clusters[temp] << endl;
            }
            clusters[i] = i;
            cout << location << ' ' << i << endl;
        }            
    }

    if (judge) {
        cout << "No optimization needed" << endl;
    }
}
