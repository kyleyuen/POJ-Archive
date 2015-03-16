#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

map<string, int> Haab;
void initialize_Haab();
void convert(int day, string& month, int year, vector<int>& d, vector<string>& m, vector<int>& y, int i);

int main()
{
    initialize_Haab();
    int n;
    cin >> n;
    
    int day;
    string day_str;;
    string month;
    int year;
    vector<int> day_print(n);
    vector<string> month_print(n);
    vector<int> year_print(n);
    
    int count = 0;
    while (count != n) {
        cin >> day_str >> month >> year;
        istringstream is(day_str.c_str());;
        is >> day;
        convert(day, month, year, day_print, month_print, year_print, count);
        ++count;
    }
    
    cout << n << endl;
    for (int i = 0; i != n; ++i) {
        cout << day_print[i] << ' ' << month_print[i] << ' ' << year_print[i] << endl;
    }
    return 0;
}

void initialize_Haab()
{
    Haab["pop"] = 0;
    Haab["no"] = 1;
    Haab["zip"] = 2;
    Haab["zotz"] = 3;
    Haab["tzec"] = 4;
    Haab["xul"] = 5;
    Haab["yoxkin"] = 6;
    Haab["mol"] = 7;
    Haab["chen"] = 8;
    Haab["yax"] = 9;
    Haab["zac"] = 10;
    Haab["ceh"] = 11;
    Haab["mac"] = 12;
    Haab["kankin"] = 13;
    Haab["muan"] = 14;
    Haab["pax"] = 15;
    Haab["koyab"] = 16;
    Haab["cumhu"] = 17;
}

void convert(int day, string& month, int year, vector<int>& d, vector<string>& m, vector<int>& y, int i)
{
    int total_day = day + Haab[month] * 20 + year * 365;
    y[i] = total_day / 260;
    
    int remain = total_day % 260;
    d[i] = (remain+1) % 13;
    
    switch (remain % 20) {
        case 0:
            m[i] = "imix";
            break;
        case 1:
            m[i] = "ik";
            break;
        case 2:
            m[i] = "akbal";
            break;
        case 3:
            m[i] = "kan";
            break;
        case 4:
            m[i] = "chicchan";
            break;
        case 5:
            m[i] = "cimi";
            break;
        case 6:
            m[i] = "manik";
            break;
        case 7:
            m[i] = "lamat";
            break;
        case 8:
            m[i] = "muluk";
            break;
        case 9:
            m[i] = "ok";
            break;
        case 10:
            m[i] = "chuen";
            break;
        case 11:
            m[i] = "eb";
            break;
        case 12:
            m[i] = "ben";
            break;
        case 13:
            m[i] = "ix";
            break;
        case 14:
            m[i] = "mem";
            break;
        case 15:
            m[i] = "cib";
            break;
        case 16:
            m[i] = "caban";
            break;
        case 17:
            m[i] = "eznab";
            break;
        case 18:
            m[i] = "canac";
            break;
        case 19:
            m[i] = "ahau";
            break;
        default:
            ;
    }
}