#include <iostream>
#define _ ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

int main() {
    _

    int X, Y;
    cin >> X >> Y;
    if(X % Y == 0)
        cout << X / Y;
    else
        cout << X / Y + 1;

    return 0;
}
