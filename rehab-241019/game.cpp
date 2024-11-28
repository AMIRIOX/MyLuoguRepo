#include <bits/stdc++.h>
using namespace std;

void solve() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    if(a < b) swap(a, b);
    
    if(a - b >= 2) printf("1\n");
    else if(a == b + 1) {
        printf("%.8lf\n", 1.0 - pow(0.5, floor((a + b) / 2)));
    } else {
        double ans = 1;
        a--;
        for(; a > 0; a--, b--) {
            ans *= a / (a + b);
        }
        printf("%.8lf\n", 1.0 - ans);
    }
}

signed main() {
    int t = 1; scanf("%d", &t);
    while(t--) solve();
    return 0;
}
