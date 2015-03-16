#include <iostream>
#include <vector>
#include <string>

using namespace std;

int inversion(string& s);
vector<int> order(vector<int>& vec);

int main()
{
    int m, n;
    cin >> n >> m;
    
    vector<string> svec(m);
    vector<int> ivec(m);
    for (vector<string>::size_type i = 0; i != svec.size(); ++i) {
        cin >> svec[i];
        ivec[i] = inversion(svec[i]);
    }
    
    ivec = order(ivec);
    for (vector<int>::size_type n = 0; n != ivec.size(); ++n) {
        cout << svec[ivec[n]] << endl;
    }
    
    return 0;
}

int inversion(string& s)
{
    int count = 0;
    for (string::iterator iter = s.begin(); iter != s.end() - 1; ++iter) {
        for (string::iterator it = iter + 1; it != s.end(); ++it) {
            if (*iter > *it) {
                ++count;
            }
        }
    }
    return count;
}

vector<int> order(vector<int>& vec)
{
    vector<int> v(vec.size());
    for (vector<int>::size_type n = 0; n != v.size(); ++n) {
        v[n] = n;
    }
    
    for (int j = 1; j != vec.size(); ++j) {
        int key = vec[j];
        int i = j - 1;
        while (i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            v[i + 1] = v[i];
            --i;
        }
        vec[i + 1] = key;
        v[i + 1] = j;
    }
    
    return v;
}