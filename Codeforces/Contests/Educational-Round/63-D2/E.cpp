#include <iostream>

typedef long long LL;

using namespace std;

const int mod = 1000003;
LL A[20][20];
LL B[20];

LL sub(LL a, LL b){
    return ((a - b) % mod + mod) % mod; 
}

LL mul(LL a, LL b){
    return ((a * b) % mod + mod) % mod;
}

LL powe(LL i, int j){
    if(j==0) return 1;
    if(j&1)
        return (i*powe(i, j-1)) % mod;
    
    LL x = powe(i, j/2);
    return (x*x) % mod;
}

// Fermats Little Theorem
LL mul_inv(LL a){
    return powe(a, mod-2);
}

LL eval(LL x){
    LL y = 0;
    for(int i=0; i<11;i++)
        y += B[i]*powe(x, i);
    return y % mod;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    for(int i=0;i<=10;i++){
        cout << "? " << i << '\n';
        int x;
        cin >> x;
        A[i][0] = 1;
        for(int j=1;j<=10;j++)
            A[i][j] = powe(i, j);
        B[i] = x;
    }

    LL mult;
    for(int i=0;i<11;i++){
        int nx = i;
        while(nx < 11 && A[nx][i] == 0) nx++;
        if(nx == 11){
            // No or infinity solutions
            cout << "! -1\n";
            exit(0);
        }
        if(nx != i){
            swap(A[nx], A[i]);
            swap(B[nx], B[i]);
        }

        // Nomoralize current row
        if(A[i][i] != 1){
            mult = mul_inv(A[i][i]);
            for(int j=0;j<11;j++)
                A[i][j] = mul(A[i][j], mult);
            B[i] = mul(B[i], mult);
        }

        // Row reduction
        for(int j=0;j<11;j++){
            if(j == i) continue;
            if(A[j][i] != 0){
                mult = A[j][i];
                for(int k=0;k<11;k++)
                    A[j][k] = sub(A[j][k], mul(mult, A[i][k]));
                B[j] = sub(B[j], mul(mult, B[i]));
            }
        }
    }

    for(int i=0; i<mod;i++){
        if(eval(i) == 0){
            cout << "! " << i << '\n';
            return 0;
        }
    }

    cout << "! -1\n";

    return 0;
}
