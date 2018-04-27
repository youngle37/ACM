#include <iostream>
#include <string>

using namespace std;

bool right(int guess, string s){
    int count = 0;
    for(int i=0;i<4;++i){
        if(s[i] == 'O')
            count += 5;
    }

    return guess == count;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int turn;
        cin >> turn;

        int A_won = 0, B_won = 0;
        bool A = true;
        string result;
        int guess;

        for(int i=0;i<turn;++i){
            cin >> guess >> result;
            if(right(guess, result))
                A ? A_won++ : B_won++;

            if(A)
                A = false;
            else
                A = true;
        }

        cout << A_won << ' ' << B_won << '\n';
    }

    return 0;
}
