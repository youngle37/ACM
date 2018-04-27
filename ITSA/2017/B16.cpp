#include <iostream>
#include <string>

using namespace std;

int main() {
    string zodiac[12] = {"tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig", "rat", "ox"};
    int T;
    cin >> T;
    while(T--) {
        int year, diff;
        cin >> year;

        diff = year - 2010;

        cout << zodiac[diff % 12] << '\n';
    }

    return 0;
}
