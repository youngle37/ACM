#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

#define pdd pair<double, double>
#define mp(a,b) make_pair(a, b)

using namespace std;

pdd out(pdd a, pdd b, pdd c) {
    double d;
    d = (a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second)) * 2;
    double A2, B2, C2;
    A2 = a.first * a.first + a.second * a.second;
    B2 = b.first * b.first + b.second * b.second;
    C2 = c.first * c.first + c.second * c.second;
    double Ox, Oy;
    Ox = (A2 * (b.second - c.second) + B2 * (c.second - a.second) + C2 * (a.second - b.second)) / d;
    Oy = (A2 * (c.first - b.first) + B2 * (a.first - c.first) + C2 * (b.first - a.first)) / d;

    return mp(Ox, Oy);
}

bool in_circle(pdd c, double r, pdd a) {
    double x = abs(c.first - a.first);
    double y = abs(c.second - a.second);
    return x * x + y * y - r * r > 1e-6 ? false : true;
}

double dis(pdd a, pdd b){
    double x = a.first - b.first;
    double y = a.second - b.second;

    return pow(x*x+y*y, 0.5);
}

bool all_in_circle(pdd c, double r, vector<pdd> &coord){
    int count = 0;
    for(int i=0;i<coord.size();++i){
        if(!in_circle(c, r, coord[i]))
            count++;
    }

    return count > 4 ? false : true;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);

        vector<pdd> coord;
        double a, b;
        for(int i = 0; i < n; ++i) {
            scanf("%lf %lf", &a, &b);
            coord.push_back(mp(a, b));
        }

        pdd temp;
        double temp_r;
        bool found = false;
        pdd ans;
        double ans_r = 1000001.0;
        // 直徑 窮舉？
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                temp = mp((coord[i].first+coord[j].first)/2, (coord[i].second+coord[j].second)/2);
                temp_r = dis(coord[i], coord[j])/2;
                if(all_in_circle(temp, temp_r, coord)){
                    found = true;
                    if(temp_r < ans_r){
                        ans = temp;
                        ans_r = temp_r;
                    }
                }
            }
        }

        pdd another;
        double another_r = 1000001.0;
        // 3點共圓 窮舉？
        for(int i = 0; i < n - 2; ++i) {
            for(int j = i + 1; j < n - 1; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    temp = out(coord[i], coord[j], coord[k]);
                    temp_r = dis(temp, coord[i]);
                    if(all_in_circle(temp,temp_r, coord)){
                        found = true;
                        if(temp_r < another_r){
                            another = temp;
                            another_r = temp_r;
                        }
                    }
                }
            }
        }

        if(another_r > ans_r){
            printf("%.9f %.9f %.9f\n", ans.first, ans.second, ans_r);
        } else{
            printf("%.9f %.9f %.9f\n", another.first, another.second, another_r);
        }

    }

    return 0;
}
