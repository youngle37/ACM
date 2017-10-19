/*
 * 找出重疊最多的那個點即為答案
 */

#include <stdio.h>
#include <utility>
#define pub pair<unsigned int, bool>

using namespace std;

pair<unsigned int, bool> *pArr;

void merge(pub*p, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    pub L[n1], R[n2];

    for(int i = 0; i < n1; ++i)
        L[i] = p[l + i];
    for(int j = 0; j < n2; ++j)
        R[j] = p[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            p[k] = L[i];
            ++i;
        } else {
            p[k] = R[j];
            ++j;
        }
        ++k;
    }

    while(i < n1) {
        p[k] = L[i];
        ++i;
        ++k;
    }

    while(j < n2) {
        p[k] = R[j];
        ++j;
        ++k;
    }
}

void merge_sort(pub *p, int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        merge_sort(p, l, m);
        merge_sort(p, m + 1, r);
        merge(p, l, m, r);
    }
}

int main() {

    int T;
    scanf("%d", &T);

    while(T--) {
        int n;
        scanf("%d", &n);

        pArr = new pair<unsigned int, bool> [n * 2];
        int pLen = 0;
        for(int i = 0; i < n; ++i) {
            scanf("%u", &pArr[pLen].first);
            pArr[pLen].second = 0;

            ++pLen;

            scanf("%u", &pArr[pLen].first);
            pArr[pLen].second = 1;

            ++pLen;
        }

        merge_sort(pArr, 0, pLen - 1);

        int max = 0;
        int temp = 0;
        for(int i=0;i<pLen;++i){
            if(pArr[i].second)
                --temp;
            else
                ++temp;

            if(temp > max)
                max = temp;
        }

        printf("%d\n", max);
    }

    return 0;
}
