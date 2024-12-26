#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 10;
constexpr double eps = 1e-5;

int n; double p;
double a[maxn], b[maxn];
bool check(double mid) {
    // (b[i] + x)/a[i] >= mid
    double dt = 0;
    for(int i = 1; i <= n; i++)
        dt += max(0.0, mid * a[i] - b[i]);
    return dt <= p * mid;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n >> p;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    /*
    //  n    p
        3    5
    // a[i] b[i]
        4    3
        5    2
        6    1
    // ansp = min(bi/ai)
    */
    double l = 0, r = 1e10;
    while(r - l > eps) {
        double mid = l + (r - l) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    if(abs(l - 1e10) < eps) printf("-1\n");
    else printf("%.9lf\n", l);
    return 0;
}

