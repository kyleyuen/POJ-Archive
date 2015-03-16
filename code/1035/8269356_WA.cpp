#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

void solve();
void construct(vector<string>& dictionary);
vector<string> detect_similarity(const vector<string>& dictionary, const string& word);
void sort_words(vector<string>& dictionary, vector<string>& result);
void print(const string& word, const vector<string>& result);

int main()
{
    solve();
    
    return 0;
}

void solve()
{
    vector<string> dictionary;
    construct(dictionary);
    
    string word;
    while (cin >> word) {
        if (word == "#") {
            break;
        }
        
        if (find(dictionary.begin(), dictionary.end(), word) == dictionary.end()) {
            vector<string> result = detect_similarity(dictionary, word);
            sort_words(dictionary, result);
            print(word, result);
        }
        else {
            cout << word << " is correct" << endl;
        }
    }
}

void construct(vector<string>& dictionary)
{
    string word;
    while (cin >> word) {
        if (word == "#") {
            break;
        }
        dictionary.push_back(word);
    }
}

//在字典中查找与给定单词相似的单词 
vector<string> detect_similarity(const vector<string>& dictionary, const string& word)
{
    vector<string> result;
    for (vector<string>::size_type i = 0; i != dictionary.size(); ++i) {
        int similarity = 0;
        for (string::size_type j = 0, k = 0; j != word.size(); ++j, ++k) {
            if (dictionary[i][k] == word[j]) {
                ++similarity;
            }
            else if (dictionary[i].size() != word.size()) {
                if (k + 1 < dictionary[i].size() && dictionary[i][k + 1] == word[j]) {                    
                    ++k;
                    ++similarity;
                }
                else if (j + 1 < word.size() && dictionary[i][k] == word[j + 1]) {
                    ++j;
                    ++similarity;
                }
                else {
                    break;
                }
            }
        }
        if ((similarity + 1 == dictionary[i].size() && dictionary[i].size() == word.size())
            || (similarity + 1 == dictionary[i].size() && dictionary[i].size() == word.size() + 1)
            || (similarity + 1 == word.size() && dictionary[i].size() + 1 == word.size()))
        {
            result.push_back(dictionary[i]);
        }
    }
    return result;
}

void sort_words(vector<string>& dictionary, vector<string>& result)
{
    vector<int> key;
    for (vector<string>::size_type i = 0; i != result.size(); ++i) {
        for (vector<string>::size_type j = 0; j != dictionary.size(); ++j) {
            if (dictionary[j] == result[i]) {
                key.push_back(j);
                break;
            }
        }
    }
    
    for (int i = 0; i != key.size(); ++i) {
        int temp = key[i];
        string s = result[i];
        int j = i - 1;
        while (0 <= j && temp < key[j]) {
            key[j + 1] = key[j];
            result[j + 1] = result[j];
            --j;
        }
        key[j + 1] = temp;
        result[j + 1] = s;
    }
}

void print(const string& word, const vector<string>& result)
{
    cout << word << ':';
    for (vector<string>::const_iterator iter = result.begin(); iter != result.end(); ++iter) {
        cout << ' ' << *iter;
    }
    cout << endl;
}
