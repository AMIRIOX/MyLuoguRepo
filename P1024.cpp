#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;
constexpr double eps = 1e-11;

double func(double mid) {
    return a * mid * mid * mid + b * mid * mid + c * mid + d;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> a >> b >> c >> d;

    int cnt = 0;
    for(int i = -100; i < 100; i++) {
        double l = i, r = i + 1;
        double x1 = func(l), x2 = func(r);

        if(!x1 /*fabs(x1) < eps*/) {
            printf("%.2lf ",l); 
            cnt++;
        }

        if(x1 * x2 >= 0) continue;
        while(r - l > eps) {
            double mid = l + (r - l) / 2;
            if(func(mid) * func(r) < 0) l = mid;
            else r = mid;
        }
        printf("%.2lf ", l);
        cnt++;
        if(cnt == 3) break;
    }

    return 0;
}
