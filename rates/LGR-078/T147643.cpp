#include <cstdio>
#include <cstring>
#include <iostream>
#define int long long
#define INF 9223372036854775800LL
using namespace std;
const int maxn = 1e3;
int gr[maxn][maxn], ans, visx[maxn][maxn];
int n;
void dfs(int u, int val=0) {
    bool into=false;
    for (int i = 1; i <= maxn; i++) {
        if (gr[u][i]  && !visx[u][i]) {
            into=true;
            // cout << u << ' ' << i << endl;
            visx[u][i]=1;
            dfs(gr[u][i],val+1);
            visx[u][i]=0;
        }
    }
    if(!into) {
        ans=max(ans,val);
    }
}
signed main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(visx, 0, sizeof(visx));
        for (int i = 1; i <= n; i++) {
            ans = -INF;
            for (int j = 1; j <= n; j++) {
                if(i!=j) gr[i][j] = gr[j][i] = 1;
            }
        }
        for (int i = 1; i <= n; i++) dfs(i);
        cout << ans << endl;
    }
    return 0;
}