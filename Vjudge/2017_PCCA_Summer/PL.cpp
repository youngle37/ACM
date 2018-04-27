#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int row, col;
    while(cin >> row >> col) {
        set<int> x;
        set<int> y;

        string line;
        cin.ignore(256, '\n');
        for(int i = 0; i < row; ++i) {
            getline(cin, line);
            for(int j = 0; j < col; ++j) {
                if(line.at(j) == 'S') {
                    x.insert(i);
                    y.insert(j);
                }
            }
        }

        cout << row*col - x.size()*y.size() << '\n';
    }

    return 0;
}
