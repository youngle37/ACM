#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
int free_count;
int ans;
int now[55][55] = {0};
vector<string> map(55);

int check(int i, int j){
    if(map[i][j] != '.')
        return 0;

    if(map[i-1][j] != '.' || map[i+1][j] != '.' || map[i][j-1] != '.' || map[i][j+1] != '.')
        return 0;

    if(now[i-1][j] != 0 || now[i+1][j] != 0 || now[i][j-1] != 0 || now[i][j+1] != 0)
        return 0;

    now[i-1][j] = 1;
    now[i+1][j] = 1;
    now[i][j-1] = 1;
    now[i][j+1] = 1;
    now[i][j] = 1;
    return 1;
}

int main(){
    cin >> n;

    free_count = 0;
    for(int i=0; i<n; i++){
        cin >> map[i];
        for(int j=0; j<n; j++){
            if(map[i][j] == '.')
                ++free_count;
        }
    }

    if(free_count%5 != 0){
        cout << "NO\n";
        return 0;
    }

    if(map[0][0] == '.' || map[0][n-1] == '.' || map[n-1][0] == '.' || map[n-1][n-1] == '.'){
        cout << "NO\n";
        return 0;
    }

    int beginX = 1, endX = n-2;
    int beginY = 1, endY = n-2;
    int nice = 0;
    ans = 0;
    while(nice == 0){
        for(int j=beginX; j<=endX; j++){
            if(check(beginY, j)){
                ans++;
                if(ans == free_count/5){
                    nice = 1;
                    break;
                }
            }
        }
        beginY++;
        if(beginY > endY)
            break;

        for(int i=beginY; i<=endY; i++){
            if(check(i, endX)){
                ans++;
                if(ans == free_count/5){
                    nice = 1;
                    break;
                }
            }
        }
        endX--;
        if(endX < beginX)
            break;

        for(int j=endX; j>=beginX; j--){
            if(check(endY, j)){
                ans++;
                if(ans == free_count/5){
                    nice = 1;
                    break;
                }
            }
        }
        endY--;
        if(endY < beginY)
            break;

        for(int i=endY; i>=beginY; i--){
            if(check(i, beginX)){
                ans++;
                if(ans == free_count/5){
                    nice = 1;
                    break;
                }
            }
        }
        beginX++;
        if(beginX > endX)
            break;

    }

    if(nice == 1 && ans == free_count/5){
        cout << "YES\n";
    } else{
        cout << "NO\n";
    }

    return 0;
}
