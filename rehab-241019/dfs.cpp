#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
const int maxm = 5e6 + 10;
int n, k, ans;
int a[maxn], vis[maxn];
int isp[maxm];

void era() {
    isp[0] = isp[1] = 1; // 0, 1 be not prime
    for(int i = 2; i * i <= maxm; i++) {
        // calculate 2~maxm instead of 2~n !!!
        // you idiot !
        if(!isp[i])
        for(int j = i << 1; j < maxm; j += i) {
            isp[j] = 1;
        }
    }
}
void dfs(int cur, int cnt, int sum) {
    if(cnt == k && !isp[sum]) {
        ans++; return;
    }
    if(cur > n) return;
    dfs(cur + 1, cnt + 1, sum + a[cur]); 
    dfs(cur + 1, cnt, sum);
}
signed main() {
    era();
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
