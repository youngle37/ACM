#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        char buf[5000];
        const char *del = " ";
        char *s;

        setbuf(stdin, NULL);

        fgets(buf, 5000, stdin);
        s = strtok(buf, del);

        vector<int> num(300);
        int cnt = 0;

        while(s != NULL) {
            sscanf(s, "%d", &num[cnt]);
            ++cnt;
            s = strtok(NULL, del);
        }

        vector<int> ans;
        if(num[0] > num[1])
            ans.push_back(0);

        for(int i = 1; i < cnt - 1; ++i) {
            if(num[i] > num[i-1] && num[i] > num[i+1])
                ans.push_back(i);
        }

        if(num[cnt-1] > num[cnt-2])
            ans.push_back(cnt-1);

        printf("%d", ans[0]);
        for(int i=1;i<ans.size();++i)
            printf(" %d", ans[i]);

        printf("\n");
    }

    return 0;
}
