/*
ID: Young Le
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int leap_count = 300;
bool leap = false;

void isleap(int year){
    if(year % 400 == 0)
        leap = true;
    else if(year % 100 == 0)
        leap = false;
    else if(year % 4 == 0)
        leap = true;
    else
        leap = false;
}

int day_month(int month){
    switch(month){
        case 1:
            return 31;
        case 2:
            if(leap)
                return 29;
            else
                return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
    }
    return 0;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    
    int N;
    fin >> N;

    int week = 0;
    int day = 1;
    int month = 1;
    int year = 1900;

    int ans[7] = {0, 0, 0, 0, 0, 0, 0};

    int dis;

    while(true){
        if(year == 1900+N)
            break;
        day = 13;
        week += 5;
        week %= 7;
        ++ans[week];
        dis = day_month(month) - 12;
        if(month == 12){
            month = 1;
            ++year;
            isleap(year);
        }
        else
            ++month;
        week += dis;
        week %= 7;
        day = 1;
    }

    for(int i=0; i<7; ++i){
        if(i == 6)
            fout << ans[4] << endl;
        else
            fout << ans[(i+5)%7] << " ";
    }
        

    return 0;
}
