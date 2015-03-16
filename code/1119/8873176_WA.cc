#include <iostream>
#include <cstdio>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

map<string, int> keyword;

void construct_keyword_map(map<string, int>& keyword);
bool solve();

int main()
{
    construct_keyword_map(keyword);
    string line;
    getline(cin, line);

    while (solve());
    return 0;
}

void construct_keyword_map(map<string, int>& keyword)
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    string word;
    while (iss >> word) {
        keyword[word] = 0;
    }
}

bool solve()
{
    double score = 0;
    string line;
    getline(cin, line);
    if (line == "----------") {
        return false;
    }

    while (line != "----------") {
        for (string::iterator iter = line.begin(); iter != line.end(); ++iter) {
            if (ispunct(*iter)) {
                *iter = ' ';
            }
            else if (isupper(*iter)) {
                *iter = tolower(*iter);
            }
        }

        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (keyword.count(word)) {
                ++keyword[word];
            }
        }
        getline(cin, line);
    }

    for (map<string, int>::iterator iter = keyword.begin(); iter != keyword.end(); ++iter) {
        if (iter->second != 0) {
            score += sqrt(iter->second);
            iter->second = 0;
        }
    }
    printf("%.2f\n", score);
    return true;
}
