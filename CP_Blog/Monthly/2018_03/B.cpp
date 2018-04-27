#include <cstdio>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        long long ans, five, ten, fifty, V;
        scanf("%lld%lld%lld%lld%lld", &ans, &five, &ten, &fifty, &V);

        if(V % 5 == 0) {
            printf("%lld\n", ans);
            continue;
        }

        long long money = five * 5 + ten * 10 + fifty * 50;
        long long once = (V+4)/5 * 5;
        long long one = once - V;
        ans += (money / once) * one;
        printf("%lld\n", ans);
    }

    return 0;
}
