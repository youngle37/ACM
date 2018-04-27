#include <stdio.h>
#include <string>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int month, day;
        scanf("%d %d", &month, &day);

        string ans;
        switch(month){
            case 1:
                ans = day >= 21 ? "Aquarius" : "Capricorn";
                break;
            case 2:
                ans = day >= 19 ? "Pisces" : "Aquarius";
                break;
            case 3:
                ans = day >= 21 ? "Aries" : "Pisces";
                break;
            case 4:
                ans = day >= 21 ? "Taurus" : "Aries";
                break;
            case 5:
                ans = day >= 22 ? "Gemini" : "Taurus";
                break;
            case 6:
                ans = day >= 22 ? "Cancer" : "Gemini";
                break;
            case 7:
                ans = day >= 23 ? "Leo" : "Cancer";
                break;
            case 8:
                ans = day >= 24 ? "Virgo" : "Leo";
                break;
            case 9:
                ans = day >= 24 ? "Libra" : "Virgo";
                break;
            case 10:
                ans = day >= 24 ? "Scorpio" : "Libra";
                break;
            case 11:
                ans = day >= 23 ? "Sagittarius" : "Scorpio";
                break;
            case 12:
                ans = day >= 22 ? "Capricorn" : "Sagittarius";
                break;
        }

        printf("%s\n", ans.c_str());
    }
    return 0;
}
