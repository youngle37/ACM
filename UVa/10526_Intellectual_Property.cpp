#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define INF 0x3fffffff

int k;
char str[50505];
int s[155555];

int tdp, n, an;

int sa[155555];
int t[155555], t2[155555], c[155555];

int height[155555];
int Rank[155555];

int v[155555];

struct Ans {
    int len, pos;
    Ans() {};
    Ans(int len, int pos) {
        this->len = len;
        this->pos = pos;
    }
} ans[155555];

bool cmp(Ans a, Ans b) {
    if (a.len == b.len) return a.pos < b.pos;
    return a.len > b.len;
}

void input() {
    n = 0;
    an = 0;

    gets(str);
    while(gets(str)) {
        if(strcmp(str, "END TDP CODEBASE") == 0)
            break;

        int len = strlen(str);
        str[len] = '\n';
        for(int i = 0; i <= len; i++)
            s[n++] = str[i];
    }

    tdp = n;
    s[n++] = 257;

    gets(str);
    while(gets(str)) {
        if(strcmp(str, "END JCN CODEBASE") == 0)
            break;

        int len = strlen(str);
        str[len] = '\n';
        for(int i = 0; i <= len; i++)
            s[n++] = str[i];
    }

    s[n] = 0;
}

void get_SA(int m) {
    n++;

    int *x = t;
    int *y = t2;

    /* Counting Sort */
    for(int i = 0; i < m; i++) c[i] = 0;        // 所有ASCII歸零
    for(int i = 0; i < n; i++) c[x[i] = s[i]]++; // 計算每個ASCII有多少個，順便把 x 初始為 s
    for(int i = 1; i < m; i++) c[i] += c[i - 1]; // 將 c 往後累加下去
    for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i; // 因為是 0-base 所以先減再放

    /* Doubling Algorithm */
    for(int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for(int i = n - k; i < n; i++) y[p++] = i;
        for(int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[y[i]]]++;
        for(int i = 1; i < m; i++) c[i] += c[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for(int i = 1; i < n; i++)
            x[sa[i]] = (y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k]) ? p - 1 : p++;
        if(p >= n) break;
        m = p;
    }

    n--;

}

void getHeight() {
    int k = 0;
    for(int i = 1; i <= n; i++) Rank[sa[i]] = i;
    for(int i = 0; i < n; i++) {
        if(k) k--;
        int j = sa[Rank[i] - 1];
        while(s[i + k] == s[j + k]) k++;
        height[Rank[i]] = k;
    }
}

void solve() {
    input();
    get_SA(258);
    getHeight();
    memset(v, 0, sizeof(v));

    int MIN = -1;
    for(int i = 1; i <= n; i++) {
        if(sa[i] < tdp) MIN = INF;
        else if(sa[i] > tdp) {
            if(MIN == -1) continue;
            MIN = min(height[i], MIN);
            v[sa[i] - tdp - 1] = max(MIN, v[sa[i] - tdp - 1]);
        }
    }

    MIN = -1;
    for(int i = n; i >= 1; i--) {
        if(sa[i] < tdp) MIN = INF;
        else if(sa[i] > tdp) {
            if(MIN == -1) continue;
            MIN = min(height[i + 1], MIN);
            v[sa[i] - tdp - 1] = max(MIN, v[sa[i] - tdp - 1]);
        }
    }

    int r = -1;
    for(int i = 0; i < n - tdp; i++) {
        if(i + v[i] <= r) continue;
        if(v[i] == 0) continue;
        ans[an++] = Ans(v[i], i);
        r = i + v[i];
    }

    sort(ans, ans + an, cmp);

    for(int i = 0; i < min(an, k); i++) {
        printf("INFRINGING SEGMENT %d LENGTH %d POSITION %d\n", i + 1, ans[i].len, ans[i].pos);
        for (int j = ans[i].pos + tdp + 1; j < ans[i].pos + tdp + 1 + ans[i].len; j++)
            printf("%c", s[j]);
        printf("\n");
    }
}

int main() {
    int t = 0;
    bool what = false;
    while(~scanf("%d\n", &k) && k) {
        if(what)
            printf("\n");
        else
            what = true;

        printf("CASE %d\n", ++t);
        solve();
    }

    return 0;
}
