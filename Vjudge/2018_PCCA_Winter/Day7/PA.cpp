#include <iostream>
#include <set>
#include <cmath>

using namespace std;

void Divi(set<int> &s, int n) {
    while(n % 2 == 0){
        s.insert(2);
        n /= 2;
    }

    for(int i=3; i<=sqrt(n); i+=2){
        while(n % i ==0){
            s.insert(i);
            n /= i;
        }
    }

    if(n > 2)
        s.insert(n);
}

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

int Primitive_Roots_Number(int p) {
    if(p == 2) return 1;

    int phi = p -1;
    set<int> s;
    Divi(s, p - 1);

    int ans = 0;
    bool flag;
    for(int x = 2; x < p; ++x) {
        flag = false;
        for(set<int>::iterator it = s.begin(); it != s.end(); ++it){
            if(modpow(x, phi/(*it), p) == 1){
                flag = true;
                break;
            }
        }
        if(flag == false)
            ans++;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int p;
    while(!cin.eof()){
        cin >> p;
        cout << Primitive_Roots_Number(p) << '\n';
    }

    return 0;
}
