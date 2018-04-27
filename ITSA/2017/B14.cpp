#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int A_1, A_2, B_1, B_2;
        cin >> A_1 >> A_2 >> B_1 >> B_2;
        int max_A, max_B,min_A,min_B;

        max_A = max(A_1, A_2);
        max_B = max(B_1, B_2);
        min_A = min(A_1, A_2);
        min_B = min(B_1, B_2);

        if(max_A <= max_B && min_A <= min_B) {
            cout << "YES\n";
        } else
            cout << "NO\n";
    }

    return 0;
}
