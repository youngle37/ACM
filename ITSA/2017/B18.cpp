#include <iostream>
#include <vector>
#include <set>

struct Item{
    int s1;
    int s2;
    int pos;
    Item(){
        s1 = 0, s2 = 0, pos = 0;
    }
    Item(int a,int b,int p){
        s1 = a;
        s2 = b;
        pos = p;
    }

    bool operator<(const Item& rhs) const{
        return s1 < rhs.s1 || s2 < rhs.s2;
    }

    bool operator==(const Item& rhs) const{
        return s1==rhs.s1 && s2==rhs.s2;
    }
};

using namespace std;

int P, Q, R, s1, s2;

int F(int x, int y) {
    return (Q * x + R * (x - y) * (x - y) + y) % P;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> P >> Q >> R >> s1 >> s2;

        set<Item> S;
        Item first(s1, s2, 1);
        S.insert(first);

        vector<int> val;
        val.push_back(s1);
        val.push_back(s2);

        Item temp_Item;
        int temp;
        int i = 2;
        set<Item>::iterator it;
        do{
            temp = F(val[i-2], val[i-1]);
            temp_Item.s1 = val[i-1];
            temp_Item.s2 = temp;
            temp_Item.pos = i;

            if(S.find(temp_Item) != S.end()){
                it = S.find(temp_Item);
                cout << i - it->pos << '\n';
                break;
            }

            val.push_back(temp);
            S.insert(temp_Item);
            i++;
        }while(1);
    }

    return 0;
}
