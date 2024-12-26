// !unaccepted TLE,  AC(1/13)
/*
#include <bits/stdc++.h>
using namespace std;

int n; 
#define double long double
double ans;
double ansp[18][(1 << 15) + 15];
double x[30], y[30], dis[30][30];
int vis[30];

double dis_calc(int a, int b) { 
    double dt1 = x[a] - x[b], dt2 = y[a] - y[b];
    return sqrt(dt1 * dt1 + dt2 * dt2);
}

void dfs(int cur, int stat, double cdis, int lst = 0) {
    if(cur == n + 1) {
        ans = min(ans, cdis);
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        auto &ref = ansp[i][stat + (1 << (i - 1))];
        if(ref < cdis + dis[lst][i]) continue;
        vis[i] = 1;
        ref = cdis + dis[lst][i];
        dfs(cur + 1, stat | (1 << (i - 1)), cdis + dis[lst][i], i);
        vis[i] = 0;
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n;
    x[0] = y[0] = 0;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    for(int i = 1; i <= n; i++) dis[0][i] = dis[i][0] = dis_calc(0, i);
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j <= n; j++)
            dis[i][j] = dis[j][i] = dis_calc(i, j);

    memset(ansp, 0x7f, sizeof ansp);
    ans = 2e18;

    dfs(1, 0, 0);
    printf("%.2Lf", ans);
    return 0;
}
*/

// @accpected 状态压缩动态规划
#include <bits/stdc++.h>
using namespace std;

int n;
double x[30], y[30];
double dp[18][(1 << 15) + 15];

double dis(int a, int b) { 
    double dt1 = x[a] - x[b], dt2 = y[a] - y[b];
    return sqrt(dt1 * dt1 + dt2 * dt2);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(false);
    cin >> n;
    x[0] = y[0] = 0;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    memset(dp, 127, sizeof dp);
    for(int i = 1; i <= n; i++) dp[i][1 << (i - 1)] = dis(i, 0);

    for(int S = 1; S < (1 << n); S++) {
        for(int i = 1; i <= n; i++) {
            if(! (S & (1 << (i - 1)))) continue;
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                if(! (S & (1 << (j - 1)))) continue; 
                dp[j][S] = min(dp[j][S], dp[i][S - (1 << (j - 1))] + dis(i, j));
            }
        }
    }
    double ans = 2e18;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, dp[i][(1 << n) - 1]);
    }
    printf("%.2lf\n", ans);
    return 0;
}

